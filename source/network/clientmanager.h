#pragma once
#include "networkmanager.h"
//rakNet
#include "BitStream.h"
#include "RakSleep.h"
#include "RakPeerInterface.h"
#include "RakNetTypes.h"  // MessageID
// OSG
#include <osg/ref_ptr>
#include <osg/Vec3>
// Qt
#include <QThread>
#include <vector>
// troen
#include "../forwarddeclarations.h"
#include "../input/remoteplayer.h"




namespace troen
{

	namespace networking{

		class ClientManager : public NetworkManager
		{
			Q_OBJECT
		public:
			ClientManager(TroenGame *game, QString playerName);
			void openClient(std::string connectAddr);

			bool isValidSession();
			void setInitParameters(RakNet::Packet *packet);
			virtual void handleSubClassMessages(RakNet::Packet *packet);
			void handlePlayerNameRefused();
			void registerAtServer();
			void changeOwnName(QString name);
			
		protected:
	
			bool m_isServer;
			bool m_connectedToServer;
			QString m_playerName;
			RakNet::SystemAddress m_serverAddress;
			std::shared_ptr<NetworkPlayerInfo> m_ownPlayer;
		};
	}


}