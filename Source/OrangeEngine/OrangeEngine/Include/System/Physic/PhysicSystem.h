#pragma once
#include "../../Unity/Unity.h"
#include <math.h>
#include "../../GameObject/GameObject.h"
#include "../../System/RigidBody/RigidBody.h"



using namespace std;

class PhysicSystem {

public:
	PhysicSystem();

	float groundedTol = 0.5f;

	struct CollisionPair {
		RigidBody* rbA;
		RigidBody* rbB;
	};


	struct CollisionInfo {
		float penetration;
		sf::Vector2f collisionNormal;
	};

	void AddRigidBody(RigidBody* rb);
	void IntegrateBodies(float dt);
	bool IsGrounded(RigidBody& rb);
	void CheckCollisions();

	void ResolveCollisions();
	void PositionalCorrection(CollisionPair* c);
	void UpdatePhysics(float dt);




private:
	map<CollisionPair*, CollisionInfo*> collisions;
	vector<RigidBody*> rigidbodies;

	CollisionInfo colInfo;
	float dt;

};


