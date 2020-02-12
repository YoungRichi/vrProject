#include "PhysicsEngine.h"
#include "algorithm"


bool PhysicsEngine::IsGrounded(oRigidBody * rb)
{
	for (int i = 0; i < rigidBodies.size(); i++)
	{
		if (rigidBodies[i] != rb)
		{
			if (rb->GetAABB().tRight.x < rb->GetAABB().tRight.x
				&& rb->GetAABB().tRight.x > rb->GetAABB().bLeft.x
				&& abs(rb->GetAABB().bLeft.y - rigidBodies[i]->GetAABB().tRight.y) <= groundedTol)
				return true;
		}
	}
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
	//for (int i = 0; i < rigidBodies.size() - 1; i++) 
	//{
	//	for (int j = 0; rigidBodies.at[i] < j < rigidBodies.size() - rigidBodies.at[i]; j++)
	//	{
	//		if (i != j)
	//		{
	//			CollisionPair pair;
	//			CollisionInfo info;
	//			pair.rigidbodyA = rigidBodies[i];
	//			pair.rigidbodyB = rigidBodies[j];
	//
	//			sf::Vector2f distance = rigidBodies[j]->transform->transform->getPosition() - rigidBodies[i]->transform->transform->getPosition();
	//
	//			sf::Vector2f halfSizeA = (rigidBodies[i]->GetAABB().tRight - rigidBodies[i]->GetAABB().bLeft) / 2.f;
	//			sf::Vector2f halfSizeB = (rigidBodies[j]->GetAABB().tRight - rigidBodies[j]->GetAABB().bLeft) / 2.f;
	//
	//			sf::Vector2f gap = sf::Vector2f(abs(distance.x), abs(distance.y)) - (halfSizeA + halfSizeB);
	//			
	//			if (gap.x < 0 && gap.y < 0)
	//			{
	//				if (collisions.find(pair) != collisions.end())
	//				{
	//					collisions.erase(pair);
	//				}
	//
	//				if (gap.x > gap.y)
	//				{
	//					if (distance.x > 0)
	//					{
	//						info.collisionNormal = sf::Vector2f(1.f, 0.f);
	//					}
	//					else
	//					{
	//						info.collisionNormal = sf::Vector2f(-1.f, 0.f);
	//					}
	//				}
	//				else
	//				{
	//					if (distance.y > 0)
	//					{
	//						info.collisionNormal = sf::Vector2f(0.f, 1.f);
	//					}
	//					else
	//					{
	//						info.collisionNormal = sf::Vector2f(0.f, -1.f);
	//					}
	//					info.penetration = gap.y;
	//				}
	//				collisions.insert(std::pair<CollisionPair, CollisionInfo>(pair, info));
	//			}
	//			else if (collisions.find(pair) != collisions.end())
	//			{
	//				collisions.erase(pair);
	//			}
	//		}
	//	}
	//}
}

void PhysicsEngine::ResolveCollisions()
{
	/*for (std::map<, auto>::iterator iter = collisions.begin(); iter != collisions.end(); ++iter)
	{
		CollisionPair k = iter->first;
	}*/

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
