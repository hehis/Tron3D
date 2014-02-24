#include "networkmanager.h"
#include "../constants.h"
#include <stdio.h>
#include <string.h>


//
#include <QQueue>

//raknet


using namespace troen::networking;
#define MAX_CLIENTS 10
#define SERVER_PORT 60000


enum GameMessages
{
	BIKE_POSITION_MESSSAGE = ID_USER_PACKET_ENUM + 1
};

struct bikeUpdateMessage updateMessage;

NetworkManager::NetworkManager()
{
	m_packet = new RakNet::Packet;
	peer = RakNet::RakPeerInterface::GetInstance();
	m_connectionAccepted = false;
	m_sendMessagesQueue = new QQueue<bikeUpdateMessage>();
}

void  NetworkManager::enqueueMessage(osg::Vec3 position)
{
	bikeUpdateMessage update = { position.x(), position.y(), position.z() };
	m_sendMessagesQueue->enqueue(update);
}

void NetworkManager::run()
{
	
	// subclass responsibility
	RakNet::Packet *packet;
	while (1)
	{
		for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive())
		{
			switch (packet->data[0])
			{
			case ID_REMOTE_DISCONNECTION_NOTIFICATION:
				printf("Another client has disconnected.\n");
				break;
			case ID_REMOTE_CONNECTION_LOST:
				printf("Another client has lost the connection.\n");
				break;
			case ID_REMOTE_NEW_INCOMING_CONNECTION:
				printf("Another client has connected.\n");
				break;
			case ID_CONNECTION_REQUEST_ACCEPTED:
				m_connectionAccepted = true;
				break;
			case ID_NEW_INCOMING_CONNECTION:
				printf("A connection is incoming.\n");
				break;
			case ID_NO_FREE_INCOMING_CONNECTIONS:
				printf("The server is full.\n");
				break;
			case ID_DISCONNECTION_NOTIFICATION:
				if (m_isServer){
					printf("A client has disconnected.\n");
				}
				else {
					printf("We have been disconnected.\n");
				}
				break;
			case ID_CONNECTION_LOST:
				if (m_isServer){
					printf("A client lost the connection.\n");
				}
				else {
					printf("Connection lost.\n");
				}
				break;

			case BIKE_POSITION_MESSSAGE:
			{
				RakNet::RakString rs;
				RakNet::BitStream bsIn(packet->data, packet->length, false);
				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));
				bsIn.Read(updateMessage);
				printf("%f %f %f\n", updateMessage.x, updateMessage.y, updateMessage.z);
				}
				break;

			default:
				printf("Message with identifier %i has arrived.\n", packet->data[0]);
				break;
			}
		}


		sendData();
		
	}

	//cleanup
	RakNet::RakPeerInterface::DestroyInstance(peer);
}

void NetworkManager::openServer()
{
	m_isServer = true;
	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	peer->Startup(MAX_CLIENTS, &sd, 1);

	printf("Starting the server.\n");
	// We need to let the server accept incoming connections from the clients
	peer->SetMaximumIncomingConnections(MAX_CLIENTS);
	

	//calls the run method in a seperate thread
	start();
}

void NetworkManager::sendData()
{
	//while (!m_sendMessagesQueue->empty())
	//{
		if (m_connectionAccepted)
		{

			printf("Sending.\n");
			RakNet::BitStream bsOut;
			// Use a BitStream to write a custom user message
			//Bitstreams are easier to use than sending casted structures, and handle endian swapping automatically
			bsOut.Write((RakNet::MessageID)BIKE_POSITION_MESSSAGE);
			updateMessage = m_sendMessagesQueue->dequeue();
			bsOut.Write(updateMessage);
			//peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, packet->systemAddress, false);
			peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE, 0, RakNet::UNASSIGNED_SYSTEM_ADDRESS, true);
		}
	//}
}

void NetworkManager::openClient()
{
	m_isServer = false;
	RakNet::SocketDescriptor sd;
	peer->Startup(1, &sd, 1);

	char str[512];

	printf("Enter server IP or hit enter for 127.0.0.1\n");
	gets(str);
	if (str[0] == 0){
		strcpy(str, "127.0.0.1");
	}
	printf("Starting the client.\n");
	RakNet::ConnectionAttemptResult r= peer->Connect(str, SERVER_PORT, 0, 0);

	//calls the run method in a seperate thread
	start();
}
