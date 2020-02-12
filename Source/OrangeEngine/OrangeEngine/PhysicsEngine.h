#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "oRigidBody.h"
#include <vector>
#include <cmath>

class oRigidBody;

float DotProduct(sf::Vector2f, sf::Vector2f);

class PhysicsEngine
{
	struct CollisionPair {
		oRigidBody* rigidbodyA;
		oRigidBody* rigidbodyB;
	};
	
	struct CmpCollisionPair
	{
		bool operator()(CollisionPair const& lhs, CollisionPair const& rhs) const;
	};

	struct CollisionInfo {
		sf::Vector2f collisionNormal;
		float penetration;
	};

private: 
	float groundedTol = 0.1f;
	std::map<CollisionPair, CollisionInfo, CmpCollisionPair> collisions;
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
	void UpdatePhysics(float sec);


	PhysicsEngine();
	~PhysicsEngine();
};

