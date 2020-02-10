#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "oRigidBody.h"
#include <vector>

class PhysicsEngine : 
{
	struct CollisionPair {
		oRigidBody* rigidbodyA;
		oRigidBody* rigidbodyB;
	};

	struct CollisionInfo {
		sf::Vector2f collisionNormal;
		float penetration;
	};

private: 
	float groundedTol = 0.1f;
	std::map<CollisionPair, CollisionInfo> collisions;
	std::vector<oRigidBody*> rigidBodies;
	//std::list<oRigidBody*> rigidBodies;
	//std::list<oRigidBody*>::iterator ob = rigidBodies.begin();
	


public:
	bool IsGrounded(oRigidBody* rb);
	void AddRigidBody(oRigidBody* rb);
	void IntegrateBodies(float  dT);
	void CheckCollisions();
	void ResolveCollisions();
	void PositionalCorrection(CollisionPair c);
	void UpdatePhysics();


	PhysicsEngine();
	~PhysicsEngine();
};

