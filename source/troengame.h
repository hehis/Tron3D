#pragma once
// Qt
#include <QThread>
#include <QMetaType>
#include <QColor>
// OSG
#include <osg/ref_ptr>
#include <osg/ShapeDrawable>
#include <osgGA/GUIEventAdapter>
#include <osg/Group>
#include <osgViewer/ViewerEventHandlers>
// troen
#include "forwarddeclarations.h"
#include "resourcepool.h"
#include "view/skydome.h"


#define MAX_BIKES 6
namespace troen
{
	class GameConfig
	{
	public:
		int numberOfPlayers;
		int timeLimit;
		int* playerInputTypes;
		QColor* playerColors;
		QString* playerNames;
		bool fullscreen;
		bool usePostProcessing;
		bool useDebugView;
		bool testPerformance;
		bool useReflection;
		bool ownView[MAX_BIKES];
	};
}
Q_DECLARE_METATYPE(troen::GameConfig)

namespace troen
{
	class TroenGame : public QObject
	{
		Q_OBJECT

	public:
		TroenGame(QThread* thread = nullptr);

		// getters
		osg::ref_ptr<GameEventHandler> getGameEventHandler();
		osg::ref_ptr<osgViewer::StatsHandler> getStatsHandler()
			{ return m_statsHandler; };
		std::shared_ptr<LevelController> getLevelController()
			{ return m_levelController; };
		std::vector<std::shared_ptr<Player>> getPlayers()
			{ return m_players; };
		osg::ref_ptr<SkyDome> getSkyDome() 
			{ return m_skyDome; };
		ResourcePool getResourcePool(){ return m_resourcePool; };

		
		// Events from GameEventHandler
		void switchSoundVolumeEvent();
		void pauseEvent();

		// Logic Events
		void pauseSimulation();
		void unpauseSimulation();

		void resize(const int width,const int height);

	public slots:
		void prepareAndStartGame(const GameConfig& config);

	private:
		bool initialize();
		bool initializeInput();
		bool composeSceneGraph();
		bool initializeGameLogic();
		bool initializePhysicsWorld();

		bool shutdown();
		void startGameLoop();

		void fixCulling(osg::ref_ptr<osgViewer::View>& view);
		// fullscreen handling
		void setupForFullScreen();
		void returnFromFullScreen();
		uint m_originalWidth;
		uint m_originalHeight;

		// OSG Components
		osg::ref_ptr<GameEventHandler>		m_gameEventHandler;
		osg::ref_ptr<osg::Group>			m_rootNode;
		osg::ref_ptr<SkyDome>               m_skyDome;
		osg::ref_ptr<osgViewer::StatsHandler> m_statsHandler;
		std::shared_ptr<PostProcessing>		m_postProcessing;
		osg::ref_ptr<osg::Group>			m_sceneNode;
		//osg::ref_ptr<osg::LightSource>		m_sunLightSource;
		
		// Controllers
		std::shared_ptr<LevelController>	m_levelController;
		std::vector<std::shared_ptr<Player>>	m_players;
		std::vector<std::shared_ptr<Player>>	m_playersWithView;

		
		QThread*							m_gameThread;
		std::shared_ptr<util::ChronoTimer>	m_gameloopTimer;
		std::shared_ptr<util::ChronoTimer>	m_gameTimer;
		std::shared_ptr<PhysicsWorld>		m_physicsWorld;
		std::shared_ptr<GameLogic>			m_gameLogic;
		std::shared_ptr<sound::AudioManager> m_audioManager;

		ResourcePool m_resourcePool;

		// Startup Options
		std::shared_ptr<GameConfig> m_gameConfig;
	};
}