#include "RigidBody.h"
#include "../Physic/PhysicSystem.h"

RigidBody::RigidBody()
{
}

void RigidBody::AddRigidBodyToPhysicsSystem(PhysicSystem& PhysicsSystem)
{
	physicSystem = &PhysicsSystem;
	SetAABB();
	physicSystem->AddRigidBody(this);
}

void RigidBody::SetCurrentVelocity(sf::Vector2f velocity)
{
	currentVelocity = velocity;
}


void RigidBody::AddForce(sf::Vector2f force)
{
	currentVelocity += force;
}

void RigidBody::Stop()
{
	currentVelocity = sf::Vector2f(0.0f, 0.0f);
	totalForces = sf::Vector2f(0.0f, 0.0f);
}


void RigidBody::SetObjectMass(float objMass)
{
	mass = objMass;
}

float RigidBody::GetObjectMass()
{
	return mass;
}

void RigidBody::SetHasGravity(bool hasGravity)
{
	obeysGravity = hasGravity;
}

bool RigidBody::IsGrounded()
{
	grounded = physicSystem->IsGrounded(*this);
	return grounded;
}

sf::Vector2f RigidBody::GetRigidBodyPosition()
{
	return position;
}

void RigidBody::AddRenderComponentToRigidBody(BaseComponent* renderComponent)
{
	renderer = renderComponent;
}

void RigidBody::SetAABB()
{
	Bounds *bounds = new Bounds();
	bounds->bLeft = sf::Vector2f(0.0f, 0.0f);
	bounds->tRight = sf::Vector2f(1.0f, 1.0f);

	if (renderer)
	{
		bounds->bLeft = sf::Vector2f(renderer->GetBounds().left, renderer->GetBounds().height);
		bounds->tRight = sf::Vector2f(renderer->GetBounds().width, renderer->GetBounds().top);

		aabb.bLeft = sf::Vector2f(renderer->getShape().getOrigin().x - renderer->getShape().getSize().x / 2.0f,
			renderer->getShape().getOrigin().y - renderer->getShape().getSize().y / 2.0f);

		aabb.tRight = sf::Vector2f(renderer->getShape().getOrigin().x + renderer->getShape().getSize().x / 2.0f,
			renderer->getShape().getOrigin().y + renderer->getShape().getSize().y / 2.0f);
	}
}

void RigidBody::setPosition(sf::Vector2f newPosition)
{
	position = newPosition;
}

bool RigidBody::GetTriggeredCollision()
{
	return TriggeredCollision;
}

void RigidBody::SetTriggeredCollision(bool collision)
{
	TriggeredCollision = collision;
}

void RigidBody::Integrate(float dt)
{
	sf::Vector2f acceleration;

	if (obeysGravity && !IsGrounded())
	{
		acceleration = gravity;
	}
	else
	{
		if (std::fabsf(currentVelocity.y) < 0.05f)
		{
			currentVelocity.y = 0;
		}
	}

	acceleration += totalForces / mass;

	if (mass == 0)
		acceleration = sf::Vector2f(0.0f, 0.0f);

	currentVelocity += acceleration;

	sf::Vector2f temp = position;
	temp += currentVelocity * dt;
	position = temp;

	SetAABB();

	totalForces = sf::Vector2f(0.0f, 0.0f);
}









