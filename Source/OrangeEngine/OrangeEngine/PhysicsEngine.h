#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class oRigidBody;

class PhysicsEngine
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
	std::list<oRigidBody*> rigidBodies = {};

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

