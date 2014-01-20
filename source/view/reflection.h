#pragma once
// OSG
#include <osg/ref_ptr>
#include <osg/Group>
// STD
#include <vector>
// troen
#include "../forwarddeclarations.h"

namespace troen
{
	class Reflection
	{
		public:
			Reflection(osg::ref_ptr<osg::Group> sceneNode, osg::ref_ptr<osg::Node> reflectionSurface);

			virtual osg::ref_ptr<osg::Group> getReflectionCameraGroup();	

		protected:
			osg::ref_ptr<osg::Group> m_node;

			osg::ref_ptr<osg::Group>				cameraGroup;
			osg::ref_ptr<osg::Camera>				reflectionCamera;
			osg::ref_ptr<osg::MatrixTransform>	reflectionTransform;
	};
}