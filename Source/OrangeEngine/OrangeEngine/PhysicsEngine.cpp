#include "PhysicsEngine.h"
#include "algorithm"


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

	for (int i = 0; i < rigidBodies.size(); i++)
	{
		rigidBodies[i]->Integrate(dT);
	}
}

void PhysicsEngine::CheckCollisions()
{
	//for ()
}

void PhysicsEngine::ResolveCollisions()
{
	//for (int i = 0; i < pair; i++)
	//{

	//}
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
