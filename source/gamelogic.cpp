#include "GameLogic.h"
// STD
#include <iostream>
// bullet
#include <btBulletDynamicsCommon.h>
#include "LinearMath/btHashMap.h"

using namespace troen;

GameLogic::GameLogic(){};

GameLogic::~GameLogic(){

	delete m_world;
	delete m_solver;
	delete m_collisionConfiguration;
	delete m_dispatcher;
	delete m_broadphase;

};


void GameLogic::initialize() {


	initializeWorld();
	createLevel();
	addFence();
	// stepSimulation();

}


void GameLogic::initializeWorld() {
	// can be used to used to filter manually potential collision partners
	m_broadphase = new btDbvtBroadphase();

	m_collisionConfiguration = new btDefaultCollisionConfiguration();
	m_dispatcher = new btCollisionDispatcher(m_collisionConfiguration);

	// potential bottleneck
	m_solver = new btSequentialImpulseConstraintSolver;

	m_world = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_collisionConfiguration);

	// TODO: adjust gravity
	m_world->setGravity(btVector3(0, -0, 0));
}

void GameLogic::addRigidBodies(std::shared_ptr<std::vector<btRigidBody>> bodies) {
	
	for (auto body : *(bodies.get()))
		m_world->addRigidBody(&body);

}


void GameLogic::createLevel() {
	
}



void GameLogic::stepSimulation() {

	// TODO: remove the loop and call this method in every (n-th ?) frame (and provide the elapsed time as a parameter)

	float elapsedTime = 1 / 60.f;

	
	// TODO: mind the following constraint:
	// timeStep < maxSubSteps * fixedTimeStep
	// where the parameters are given as follows: stepSimulation(timeStep, maxSubSteps, fixedTimeStep)
		
	m_world->stepSimulation(elapsedTime, 10);

	//// holds position (center of object) and orientation
	//btTransform trans;
	//m_fallingRigidBody->getMotionState()->getWorldTransform(trans);
	//std::cout << "box Y: " << trans.getOrigin().getY()
	//			<< " X: " << trans.getOrigin().getX()
	//			<< " Z: " << trans.getOrigin().getZ()
	//			<< std::endl;

	checkForCollisions();

}


// respectively: updateFence ?
void GameLogic::addFence() {
	/*
	we want to have a concave shape (which will be updated every frame), so we got the following options:
	- btBvhTriangleMeshShape with btTriangleMesh or btTriangleIndexVertexArray as input (no difference in performance)
			"it is recommend to enable useQuantizedAabbCompression for better memory usage"
	- create independent boxes (respectively glue them together in a compoundShape)


	first approach will be: btBvhTriangleMeshShape with btTriangleMesh
	*/


	
	btTriangleMesh fenceMesh;
	/*
	the mesh will look this (I should study art)
	1 4                5 ...

	0		             2 3 ...
	*/
	
	btScalar fenceHeight = 1;
	btScalar fenceStep = 1;

	// TODO change initial value of X
	btScalar currentX = 0;

	// mind the manipulation of i within the loop
	for (int i = 0; i < 10; ++i)
	{

		currentX += fenceStep;

		fenceMesh.addTriangle(
			btVector3(currentX, 0, 0),
			btVector3(currentX, fenceHeight, 0),
			btVector3(currentX + fenceStep, 0, 0),
			false
		);

		i++;

		currentX += fenceStep;

		fenceMesh.addTriangle(
			btVector3(currentX, 0, 0),
			btVector3(currentX - fenceStep, fenceHeight, 0),
			btVector3(currentX, fenceHeight, 0),
			false
		);
	}


	btBvhTriangleMeshShape *fenceShape = new btBvhTriangleMeshShape(&fenceMesh, false);


	btTransform trans;
	trans.setIdentity();      
	trans.setOrigin(btVector3(0, 7, 0));      
	btDefaultMotionState* motionState = new btDefaultMotionState(trans);
	


	// we set localInertia to a zero vector
	// maybe, the mass has to be 0 instead of 1 ?
	btRigidBody* fenceBody = new btRigidBody(1, motionState, fenceShape, btVector3(0, 0, 0));
	

	// do we have to adjust these parameters ?
	fenceBody->setContactProcessingThreshold(BT_LARGE_FLOAT);
	fenceBody->setCcdMotionThreshold(.5);
	fenceBody->setCcdSweptSphereRadius(0);
	
	m_world->addRigidBody(fenceBody);


}

void GameLogic::checkForCollisions() {
	btDispatcher *dispatcher = m_world->getDispatcher();
	int numManifolds = dispatcher->getNumManifolds();
	

	std::cout << "[GameLogic::checkForCollisions] numManifolds " << numManifolds << std::endl;
	for (int i = 0; i < numManifolds; i++)
	{
		btPersistentManifold* contactManifold =  dispatcher->getManifoldByIndexInternal(i);

		// unnecessary (?) and not working
		// btCollisionObject* obA = static_cast<btCollisionObject*>(contactManifold->getBody0());
		// btCollisionObject* obB = static_cast<btCollisionObject*>(contactManifold->getBody1());

		int numContacts = contactManifold->getNumContacts();
		std::cout << "[GameLogic::checkForCollisions] numContacts " << numContacts << std::endl;
		for (int j=0; j < numContacts; j++)
		{
			btManifoldPoint& pt = contactManifold->getContactPoint(j);
			
			
			// access our logic representation
			// contactManifold->getBody0()->getUserPointer();


			if (pt.getDistance() < 0.f)
			{
				// probably, we should "break" here for performance

				// additional infos
				/*const btVector3& ptA = pt.getPositionWorldOnA();
				const btVector3& ptB = pt.getPositionWorldOnB();
				const btVector3& normalOnB = pt.m_normalWorldOnB;*/
				
				std::cout << "[GameLogic::checkForCollisions] collision detected" << std::endl;
			}
		}
	}
}



void GameLogic::addBike() {

}


void GameLogic::addItemBox() {

}

// ...




