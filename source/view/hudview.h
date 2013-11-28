#pragma once
// OSG
#include <osg/Referenced>
// troen
#include "../forwarddeclarations.h"
#include "abstractview.h"


namespace troen
{

	class HUDView : public AbstractView //, public osg::Referenced
	{
	public:
		HUDView();
	private:
		osg::Camera* HUDView::createHUD();
	};
}