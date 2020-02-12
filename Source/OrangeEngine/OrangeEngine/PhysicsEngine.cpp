#define NOMINMAX
#include "PhysicsEngine.h"
#include "Actor.h"

float DotProduct(sf::Vector2f f, sf::Vector2f s)
{
	return f.x * s.x + f.y * s.y;
}

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
	for (int i = 0; i < rigidBodies.size() - 1; i++) 
	{
		for (int j = i; j < rigidBodies.size(); j++)
		{
			if (i != j)
			{
				CollisionPair pair;
				CollisionInfo info;
				pair.rigidbodyA = rigidBodies[i];
				pair.rigidbodyB = rigidBodies[j];

				sf::Vector2f distance = rigidBodies[j]->GetActor()->GetTransform()->transform->getPosition() - rigidBodies[i]->GetActor()->GetTransform()->transform->getPosition();

				sf::Vector2f halfSizeA = (rigidBodies[i]->GetAABB().tRight + rigidBodies[i]->GetAABB().bLeft) / 2.f;
				sf::Vector2f halfSizeB = (rigidBodies[j]->GetAABB().tRight + rigidBodies[j]->GetAABB().bLeft) / 2.f;

				sf::Vector2f gap = sf::Vector2f(abs(distance.x), abs(distance.y)) - (halfSizeA + halfSizeB);
				
				if (gap.x < 0 && gap.y < 0)
				{
					if (collisions.find(pair) != collisions.end())
					{
						collisions.erase(pair);
					}

					if (gap.x > gap.y)
					{
						if (distance.x > 0)
						{
							info.collisionNormal = sf::Vector2f(1.f, 0.f);
						}
						else
						{
							info.collisionNormal = sf::Vector2f(-1.f, 0.f);
						}
						info.penetration = gap.x;
					}
					else
					{
						if (distance.y > 0)
						{
							info.collisionNormal = sf::Vector2f(0.f, 1.f);
						}
						else
						{
							info.collisionNormal = sf::Vector2f(0.f, -1.f);
						}
						info.penetration = gap.y;
					}
					collisions.insert(std::make_pair(pair, info));
				}
				else if (collisions.find(pair) != collisions.end())
				{
					collisions.erase(pair);
				}
			}
		}
	}
}

void PhysicsEngine::ResolveCollisions()
{
	for (auto p : collisions)
	{
		auto pair = p.first;
		float minBounce = min(pair.rigidbodyA->GetBounciness(), pair.rigidbodyB->GetBounciness());
		float velAlongNormal = DotProduct(pair.rigidbodyA->GetCurVelocity() - pair.rigidbodyA->GetCurVelocity(), collisions[pair].collisionNormal);
		if (velAlongNormal > 0) continue;

		float j = -(1 + minBounce) * velAlongNormal;
		float invMassA, invMassB;
		if (pair.rigidbodyA->GetMass() == 0)
			invMassA = 0;
		else 
			invMassA = 1.f / pair.rigidbodyA->GetMass();

		if (pair.rigidbodyB->GetMass() == 0)
			invMassB = 0;
		else
			invMassB = 1.f / pair.rigidbodyB->GetMass();

		j /= invMassA + invMassB;

		sf::Vector2f impulse = j * collisions[pair].collisionNormal;
	
		// ... update velocities
		pair.rigidbodyA->SetCurVelocity(pair.rigidbodyA->GetCurVelocity() - impulse * invMassA);
		pair.rigidbodyB->SetCurVelocity(pair.rigidbodyA->GetCurVelocity() + impulse * invMassB);

		if (abs(collisions[pair].penetration) > 0.01f) {
			PositionalCorrection(pair);
		}
	}
	

}

void PhysicsEngine::PositionalCorrection(CollisionPair c)
{
	const float percent = 0.2f;

	float invMassA, invMassB;
	if (c.rigidbodyA->GetMass() == 0)
		invMassA = 0;
	else
		invMassA = 1 / c.rigidbodyA->GetMass();

	if (c.rigidbodyB->GetMass() == 0)
		invMassB = 0;
	else
		invMassB = 1 / c.rigidbodyB->GetMass();

	sf::Vector2f correction = ((collisions[c].penetration / (invMassA + invMassB)) * percent) * -collisions[c].collisionNormal;
	auto transformA = c.rigidbodyA->GetActor()->GetTransform()->transform;
	auto transformB = c.rigidbodyB->GetActor()->GetTransform()->transform;

	sf::Vector2f temp = transformA->getPosition();
	temp -= invMassA * correction;
	transformA->setPosition(temp);

	temp = transformB->getPosition();
	temp += invMassB * correction;
	transformB->setPosition(temp);
}

void PhysicsEngine::UpdatePhysics(float sec)
{
	IntegrateBodies(sec);

	CheckCollisions();
	ResolveCollisions();
}

PhysicsEngine::PhysicsEngine()
{
}


PhysicsEngine::~PhysicsEngine()
{
}

bool PhysicsEngine::CmpCollisionPair::operator()(CollisionPair const & lhs, CollisionPair const & rhs) const
{
	return 
		lhs.rigidbodyA < rhs.rigidbodyA ||
		lhs.rigidbodyA == rhs.rigidbodyA &&
		lhs.rigidbodyB < rhs.rigidbodyB;
}
