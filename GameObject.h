#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Ogre.h>
#include <btBulletDynamicsCommon.h>
#include "OgreMotionState.h"
#include "BulletContactCallback.h"
#include "Sound.h"


class Simulator;

class GameObject
{
	protected:
		Ogre::String name;
		Ogre::SceneManager* sceneMgr;
		Simulator* simulator;
		Ogre::SceneNode* rootNode;
		Ogre::Entity* geom;
		btCollisionShape* shape;
		btScalar mass;
		btRigidBody* body;
		btTransform tr;
		btVector3 inertia;
		OgreMotionState* motionState;
		Ogre::Real restitution;
		Ogre::Real friction;
		CollisionContext* context;
		BulletContactCallback* callback;
		Sound* sounds;
		int volume;

	public:
		GameObject(Ogre::SceneManager* scnMgr, Simulator* sim, Ogre::String n);
		btRigidBody* getBody(){return body;}
		Ogre::SceneNode* getRootNode(){return rootNode;}
		Ogre::String getName(){return name;}
		void updateTransform();
		void addToSimulator();
		void setVelocity(Ogre::Real x, Ogre::Real y, Ogre::Real z);
		virtual void update(float elapsedTime);
		void setVolume(int v);
};

#endif