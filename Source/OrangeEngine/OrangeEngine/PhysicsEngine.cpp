#include "PhysicsEngine.h"



bool PhysicsEngine::IsGrounded(oRigidBody * rb)
{
	return false;
}

void PhysicsEngine::AddRigidBody(oRigidBody * rb)
{
	rigidBodies.push_back(rb);
}

void PhysicsEngine::IntegrateBodies(float dT)
{
	for (auto i = rigidBodies.begin(); i != rigidBodies.end(); ++i)
	{
		//rigidBodies[i].
	}
}

void PhysicsEngine::CheckCollisions()
{
}

void PhysicsEngine::ResolveCollisions()
{
}

void PhysicsEngine::PositionalCorrection(CollisionPair c)
{
}

void PhysicsEngine::UpdatePhysics()
{
}

PhysicsEngine::PhysicsEngine()
{
}


PhysicsEngine::~PhysicsEngine()
{
}
