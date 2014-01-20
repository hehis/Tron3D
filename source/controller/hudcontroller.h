#pragma once
//osg
#include <osg/Array>
//troen
#include "../forwarddeclarations.h"
#include "abstractcontroller.h"

namespace troen
{
	class HUDController : public AbstractController
	{
	public:

		HUDController(std::shared_ptr<BikeController> bikeController, const osg::Vec4 playerColor);
		void attachSceneToRadarCamera(osg::Group* scene);
		void resize(int width, int height);
		void update();
        void setTrackNode(osg::Node* trackNode);

	private:
		std::weak_ptr<BikeController> m_bikeController;
	};
}