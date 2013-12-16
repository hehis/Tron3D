#include "bikeview.h"
//osg
#include <osg/Texture2D>
#include <osg/TexEnv>
#include <osg/TexGen>
#include <osg/TextureCubeMap>
#include <osg/TexMat>
#include <osg/Material>
#include <osg/Geode>
#include <osgDB/WriteFile>
#include <osg/CullFace>
#include <osg/TexGenNode>
#include <osgUtil/CullVisitor>
#include <stdio.h>
// troen
#include "shaders.h"
#include "../input/bikeinputstate.h"
#include <osgDB/ReadFile>
#include <osg/PositionAttitudeTransform>

#include "../model/bikemodel.h"

using namespace troen;

BikeView::BikeView(osg::Vec3 color)
{
	m_node = new osg::Group();
	m_playerColor = color;
	pat = new osg::PositionAttitudeTransform();
	
#ifndef _DEBUG
	osg::Matrixd initialTransform;
	osg::Quat rotationQuat(osg::DegreesToRadians(180.0f), osg::Vec3d(0.0, 0.0, 1.0));
	initialTransform.makeRotate(rotationQuat);
	initialTransform *= initialTransform.scale(osg::Vec3f(5.0f, 5.0f, 5.0f));
	initialTransform *= initialTransform.translate(0.0, 0.0, -4.9);
	
	osg::MatrixTransform* matrixTransform = new osg::MatrixTransform(initialTransform);
	pat->addChild(matrixTransform);
	
	MovieCycle_Body = createCyclePart("data/models/cycle/MG_MovieCycle_Body_MI.obj",
		"data/models/cycle/MG_MovieCycle_Body_SPEC.tga",
		"data/models/cycle/MG_MovieCycle_BodyHeadLight_EMSS.tga",
		"data/models/cycle/MG_MovieCycle_Body_NORM.tga", DEFAULT);
	
	osg::ref_ptr<osg::Node> MovieCycle_Player_Body = createCyclePart("data/models/cycle/MG_MovieCycle_PlayerBody_MI.obj",
		"data/models/cycle/MG_Player_Body_SPEC.tga",
		"data/models/cycle/MG_Player_Body_EMSS.tga",
		"data/models/cycle/MG_Player_Body_NORM.tga", GLOW, 0.1);

	osg::ref_ptr<osg::Node> MovieCycle_Tire = createCyclePart("data/models/cycle/MG_MovieCycle_Tire_MI.obj",
		"",
		"data/models/cycle/MG_MovieCycle_Tire_EMSS.tga",
		"data/models/cycle/MG_MovieCycle_Tire_NORM.tga", GLOW, 0.5);

	osg::ref_ptr<osg::Node> MovieCycle_Player_Helmet = createCyclePart("data/models/cycle/MG_MovieCycle_PlayerHelmet_MI.obj",
		"data/models/cycle/MG_Player_Helmet_SPEC.tga",
		"data/models/cycle/MG_Player_Helmet_EMSS.tga",
		"data/models/cycle/MG_Player_Helmet_NORM.tga", GLOW, 0.3);

	osg::ref_ptr<osg::Node> MovieCycle_Player_Disc = createCyclePart("data/models/cycle/MG_MovieCycle_PlayerDisc_MI.obj",
		"data/models/cycle/MG_Player_Disc_SPEC.tga",
		"data/models/cycle/MG_Player_Disc_EMSS.tga",
		"data/models/cycle/MG_Player_Disc_NORM.tga", GLOW);

	osg::ref_ptr<osg::Node> MovieCycle_Glass_MI = createCyclePart("data/models/cycle/MG_MovieCycle_Glass_MI.obj",
		"data/models/cycle/Glass.tga",
		"data/models/cycle/Glass.tga",
		"", DEFAULT);

	osg::ref_ptr<osg::Node> MovieCycle_Engine = createCyclePart("data/models/cycle/MG_MovieCycle_Engine_MI.obj",
		"",
		"data/models/cycle/MG_MovieCycle_Engine_EMSS.tga",
		"data/models/cycle/MG_MovieCycle_Engine_NORM.tga", DEFAULT);

	osg::ref_ptr<osg::Node> MovieCycle_Player_Baton = createCyclePart("data/models/cycle/MG_MovieCycle_PlayerBaton_MI.obj",
		"data/models/cycle/MG_Player_Baton_SPEC.tga",
		"data/models/cycle/MG_Player_Baton_EMSS.tga",
		"data/models/cycle/MG_Player_Baton_NORM.tga", GLOW);
		
	MovieCycle_Body->asGroup()->addChild(MovieCycle_Player_Body);
	MovieCycle_Body->asGroup()->addChild(MovieCycle_Tire);
	MovieCycle_Body->asGroup()->addChild(MovieCycle_Player_Helmet);
	MovieCycle_Body->asGroup()->addChild(MovieCycle_Player_Disc);
	MovieCycle_Body->asGroup()->addChild(MovieCycle_Glass_MI);
	MovieCycle_Body->asGroup()->addChild(MovieCycle_Engine);
	MovieCycle_Body->asGroup()->addChild(MovieCycle_Player_Baton);
	matrixTransform->addChild(MovieCycle_Body);

#endif
#ifdef _DEBUG
	
	pat->addChild(osgDB::readNodeFile("data/models/cessna.osgt"));
#endif
	m_node->addChild(pat);
}

osg::ref_ptr<osg::Node> BikeView::createCyclePart(std::string objFilePath, std::string specularTexturePath,
	std::string diffuseTexturePath, std::string normalTexturePath,
	int modelIndex, float glowIntensity)
{
	enum BIKE_TEXTURES { DIFFUSE, SPECULAR, NORMAL };

	std::cout << "[TroenGame::bikeView] Loading Model \"" << objFilePath << "\"" << std::endl;
	osg::Node* Node = osgDB::readNodeFile(objFilePath);

	//osgDB::writeNodeFile(*Node, std::string("file.osg")); //to look at the scenegraph
	osg::ref_ptr<osg::StateSet> NodeState = Node->getOrCreateStateSet();

	osg::ref_ptr<osg::Geode> singleGeode = dynamic_cast<osg::Geode*>(Node->asGroup()->getChild(0));
	osg::ref_ptr<osg::StateSet> childState = singleGeode->getDrawable(0)->getStateSet();
	osg::StateAttribute* stateAttributeMaterial = childState->getAttribute(osg::StateAttribute::MATERIAL);

	osg::Uniform* modelIndexU = new osg::Uniform("modelID", modelIndex);
	NodeState->addUniform(modelIndexU);

	osg::Uniform* glowIntensityU = new osg::Uniform("glowIntensity", glowIntensity);
	NodeState->addUniform(glowIntensityU);

	if (stateAttributeMaterial != NULL)
	{
		osg::Material *objMaterial = dynamic_cast<osg::Material*>(stateAttributeMaterial);
		
		if (modelIndex != GLOW) {
			// if modelIndex == GLOW we will set it later (this avoids some ugly warnings from osg)
			osg::Vec4 diffuse = objMaterial->getDiffuse(osg::Material::FRONT_AND_BACK);
			osg::Uniform* diffuseMaterialColorU = new osg::Uniform("diffuseMaterialColor", diffuse);
			NodeState->addUniform(diffuseMaterialColorU);
		}

		osg::Vec4 ambient = objMaterial->getAmbient(osg::Material::FRONT_AND_BACK);
		osg::Uniform* ambientMaterialColorU = new osg::Uniform("ambientMaterialColor", ambient);
		NodeState->addUniform(ambientMaterialColorU);

		osg::Vec4 specular = objMaterial->getSpecular(osg::Material::FRONT_AND_BACK);
		osg::Uniform* specularMaterialColorU = new osg::Uniform("specularMaterialColor", specular);
		NodeState->addUniform(specularMaterialColorU);

		float shininess = objMaterial->getShininess(osg::Material::FRONT_AND_BACK);
		osg::Uniform* shininessU = new osg::Uniform("shininess", shininess);
		NodeState->addUniform(shininessU);
	}

	osg::Uniform* ColorU;
	if (modelIndex == GLOW) {
		ColorU = new osg::Uniform("playerColor", m_playerColor);
		// set parts to white/gray so that we can color it
		NodeState->addUniform(new osg::Uniform("diffuseMaterialColor", osg::Vec4(0.5f, 0.5f, 0.5f, 1.f)));
	}
	else {
		ColorU = new osg::Uniform("playerColor", osg::Vec3(1.f, 1.f, 1.f));
	}
	NodeState->addUniform(ColorU);

	if (specularTexturePath != "")
	{
		osg::Uniform* specularMapU = new osg::Uniform("specularTexture", SPECULAR);
		NodeState->addUniform(specularMapU);
		setTexture(NodeState, specularTexturePath, SPECULAR);
	}

	if (diffuseTexturePath != "")
	{
		osg::Uniform* diffuseMapU = new osg::Uniform("diffuseTexture", DIFFUSE);
		NodeState->addUniform(diffuseMapU);
		setTexture(NodeState, diffuseTexturePath, DIFFUSE);
	}

	if (normalTexturePath != ""){
		osg::Uniform* normalMapU = new osg::Uniform("normalTexture", NORMAL);
		NodeState->addUniform(normalMapU);
		setTexture(NodeState, normalTexturePath, NORMAL);
	}

	NodeState->setAttributeAndModes(shaders::m_allShaderPrograms[shaders::BIKE], osg::StateAttribute::ON);

	return Node;
}

void BikeView::setTexture(osg::ref_ptr<osg::StateSet> stateset, std::string filePath, int unit)
{

	osg::Image* image = osgDB::readImageFile(filePath);
	if (!image)
		std::cout << "[TroenGame::bikeView]  File \"" << filePath << "\" not found." << std::endl;
	else
	{
		osg::Texture2D* texture = new osg::Texture2D;
		texture->setImage(image);
		texture->setResizeNonPowerOfTwoHint(false);

	/*	osg::TexEnv* texenv = new osg::TexEnv;
		texenv->setMode(osg::TexEnv::BLEND);
		texenv->setColor(osg::Vec4(0.3f, 0.3f, 0.3f, 0.3f));*/

		stateset->setTextureAttributeAndModes(unit, texture, osg::StateAttribute::ON);
		//stateset->setTextureAttribute(1, texenv);

		//rootNode->setStateSet(stateset);
	}
}

void BikeView::update()
{
	MovieCycle_Body->getStateSet()->addUniform(new osg::Uniform("transform", pat->asMatrixTransform()->getMatrix()));
}
