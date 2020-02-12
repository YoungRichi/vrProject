#pragma once
#define NOMINMAX
#include <SFML/Graphics/Transform.hpp>
#include <SFML/System/Vector2.hpp>
#include "ActorComponent.h"
#include "oTransform.h"

class PhysicsEngine;
class oTransform;

class oRigidBody : public ActorComponent
{
public:
	struct AABB
	{
		sf::Vector2<float> bLeft;
		sf::Vector2<float> tRight;
	};

	oRigidBody(PhysicsEngine* phEngine);
	~oRigidBody();
	void AddForce(sf::Vector2<float> force);
	void Integrate(float dT);
	void Stop();
	bool IsGrounded();
	float GetMass() const { return mass; }
	void CalcAABB();
	float GetBounciness() const { return bounciness; }
	sf::Vector2f GetCurVelocity() const { return currentVelocity; }
	void SetBounciness(float value) { bounciness = value; }
	void SetMass(float value) { mass = value; }
	void SetCurVelocity(sf::Vector2f value) { currentVelocity = value; }
	void SetObeysGravity(bool value) { obeysGravity = value; }
	AABB GetAABB() { return aabb; }
	void SetAABB(AABB value) { aabb = value; }

private:
	sf::Vector2<float> currentVelocity;
	sf::Vector2<float> maxVelocity;
	//sf::Vector2<float> acceleration;
	sf::Vector2<float> totalForces;
	float mass = 1.0f;
	float bounciness = 1;                        // The bounciness factor (value between 0 and 1, 0 being no bounce, and 1 being super bouncy!)
	bool obeysGravity = true;                    // Whether or not this body obeys gravity
	bool grounded;
	sf::Vector2<float> gravity;
	AABB aabb;
	PhysicsEngine* physicsEngine;
};

