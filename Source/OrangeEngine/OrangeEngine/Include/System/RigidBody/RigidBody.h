#pragma once
#include "../../Unity/Unity.h"
#include "../../Components/Render/RenderComponent.h"

class PhysicSystem;

class RigidBody : public BaseComponent
{
public:
	RigidBody();

	float mass = 1.0f;
	float bounciness = 0.25f;
	bool  obeysGravity = true;
	sf::Vector2f gravity = { 0.0f, 9.80f };

	sf::Vector2f currentVelocity = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f maxVelocity = { 10.0f, 10.0f };

	void SetCurrentVelocity(sf::Vector2f velocity);

	bool grounded;

	struct AABB
	{
		sf::Vector2f bLeft;     //min
		sf::Vector2f tRight;	//max
	};

	AABB aabb;
	void AddForce(sf::Vector2f  force);
	void Stop();
	bool IsGrounded();

	void AddRenderComponentToRigidBody(BaseComponent* renderComponent);
	void SetAABB();
	void Integrate(float dt);


	sf::Vector2f position;

	sf::Vector2f GetRigidBodyPosition();

	sf::Vector2f linearVelocity;

	void AddRigidBodyToPhysicsSystem(PhysicSystem& PhysicsSystem);

	void setPosition(sf::Vector2f newPosition);

	void SetObjectMass(float objMass);

	void SetHasGravity(bool hasGravity);

	float GetObjectMass();

	bool GetTriggeredCollision();

	void SetTriggeredCollision(bool collision);


	struct Bounds {
		sf::Vector2f bLeft;
		sf::Vector2f tRight;
	};


protected:

private:
	sf::Vector2f   totalForces;
	PhysicSystem*  physicSystem;
	BaseComponent* renderer;
	bool          TriggeredCollision = false;

};

