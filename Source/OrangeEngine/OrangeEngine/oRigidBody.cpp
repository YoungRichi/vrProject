#define NOMINMAX
#include "oRigidbody.h"
#include "../../OrangeEngine.h"
#include "../GameObjectManager.h"
#include "PhysicsEngine.h"
#include "Actor.h"
#include <cmath>
#include <iostream>


oRigidBody::oRigidBody(PhysicsEngine* phEngine)
	: gravity(0, 9.8f)
	, maxVelocity(10.f, 10.f)
	, physicsEngine(phEngine)
	, aabb(aabb)
{
}


oRigidBody::~oRigidBody()
{
}

void oRigidBody::AddForce(sf::Vector2<float> force)
{
	totalForces += force;
}

void oRigidBody::Integrate(float dT) {
	sf::Vector2<float> acceleration;	
	if (obeysGravity && !IsGrounded()) {
		acceleration = gravity;
	}
	else {
		if (abs(currentVelocity.y) < 0.05f)
			currentVelocity.y = 0;
	}
	//float mass = 1.0f;
	//if (mass == NULL)
	//	return;
	acceleration += totalForces / mass;
		//acceleration = sf::Vector2f(10,1);
	if (mass == 0)
		acceleration = sf::Vector2f(0, 0);

	currentVelocity += acceleration * dT;

	sf::Vector2f temp = GetActor()->GetTransform()->GetLocation();
	//temp += currentVelocity * dT;
	GetActor()->GetTransform()->Translate(currentVelocity.x * dT, currentVelocity.y * dT);
	CalcAABB();

	totalForces = sf::Vector2f(0, 0);
}

void oRigidBody::Stop()
{
	currentVelocity = sf::Vector2f(0, 0);
	totalForces = sf::Vector2f(0, 0);
}

bool oRigidBody::IsGrounded()
{
	grounded = physicsEngine->IsGrounded(this);
	return grounded;
}

void oRigidBody::CalcAABB()
{
	sf::FloatRect bounds = GetActor()->GetTransform()->GetGlobalBounds();
	aabb.bLeft.x = bounds.left;
	aabb.bLeft.y = bounds.top + bounds.height;
	
	aabb.tRight.x = bounds.left + bounds.width;
	aabb.tRight.y = bounds.top;

	/*aabb.bLeft.x = bounds.left;
	aabb.bLeft.y = bounds.top;

	aabb.tRight.x = bounds.left + bounds.width;
	aabb.tRight.y = bounds.top - bounds.height;*/
}
