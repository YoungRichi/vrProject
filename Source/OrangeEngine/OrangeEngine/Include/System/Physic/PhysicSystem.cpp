#include "PhysicSystem.h"

PhysicSystem::PhysicSystem() {};


void PhysicSystem::AddRigidBody(RigidBody* rb)
{
	rigidbodies.push_back(rb);
}

void PhysicSystem::IntegrateBodies(float dt)
{
	for (std::vector<RigidBody*>::iterator it = rigidbodies.begin(); it != rigidbodies.end(); ++it)
	{
		(*it)->Integrate(dt);
	}
}

bool PhysicSystem::IsGrounded(RigidBody& rigidBody)
{
	for (auto rb : rigidbodies)
	{
		if (rb != &rigidBody)
		{
			if (rigidBody.aabb.bLeft.x < rb->aabb.tRight.x)
			{
				if (rigidBody.aabb.tRight.x > rb->aabb.bLeft.x)
				{
					if (std::fabsf(rigidBody.aabb.bLeft.y - rb->aabb.tRight.y) <= groundedTol)
					{
						if (std::fabsf(rigidBody.currentVelocity.y) < groundedTol)
						{

							return true;
						}
					}
				}
			}
		}
	}

	return false;
}

void PhysicSystem::CheckCollisions()
{
	for (auto bodyA : rigidbodies)
	{
		for (auto bodyB : rigidbodies)
		{
			if (bodyA != bodyB)
			{
				CollisionPair *pair = new CollisionPair();
				CollisionInfo *colInfo = new CollisionInfo();

				pair->rbA = bodyA;
				pair->rbB = bodyB;

				sf::Vector2f distance = pair->rbB->position - pair->rbA->position;

				sf::Vector2f halfSizeA = (pair->rbA->aabb.tRight - pair->rbA->aabb.bLeft) / 2.0f;
				sf::Vector2f halfSizeB = (pair->rbB->aabb.tRight - pair->rbB->aabb.bLeft) / 2.0f;

				sf::Vector2f gap = sf::Vector2f(std::fabsf(distance.x), std::fabsf(distance.y)) - (halfSizeA + halfSizeB);

				/*std::cout << "RBA: " << pair->rbA->position.x << " " << pair->rbA->position.y << endl;
				std::cout << "RBB: " << pair->rbB->position.x << " " << pair->rbB->position.y << "\n"<< endl;*/


				// Seperating Axis Theorem 
				if (gap.x < 0 && gap.y < 0)
				{
					pair->rbA->SetTriggeredCollision(true);
					pair->rbB->SetTriggeredCollision(true);

					try
					{
						if (collisions.at(pair))
						{
							collisions.erase(pair);
							std::cout << "Pair Removed" << std::endl;
						}

					}
					catch (...)
					{

					}


					if (gap.x > gap.y) {
						if (distance.x > 0) {
							// ... Update collision normal                               
							colInfo->collisionNormal = sf::Vector2f(1, 0);
						}
						else {
							// ... Update collision normal
							colInfo->collisionNormal = sf::Vector2f(-1, 0);

						}
						colInfo->penetration = gap.x;
					}
					else {
						if (distance.y > 0) {
							// ... Update collision normal
							colInfo->collisionNormal = sf::Vector2f(0, 1);
						}
						else {
							// ... Update collision normal
							colInfo->collisionNormal = sf::Vector2f(0, -1);
						}
						colInfo->penetration = gap.y;
					}

					collisions[pair] = colInfo;
				}
				else
				{
					try
					{
						if (collisions.at(pair))
						{
							collisions.erase(pair);
							std::cout << "Pair Removed" << std::endl;
						}
					}
					catch (...)
					{

					}

				}
			}
		}
	}
}

float Dot(float v1x, float v1y, float v2x, float v2y)
{
	float product = v1x * v2x + v1y * v2y;
	return product;
}

void PhysicSystem::ResolveCollisions()
{
	for (std::map<CollisionPair*, CollisionInfo*>::iterator pair = collisions.begin(); pair != collisions.end(); ++pair)
	{
		//pair->first
		float minBounce = std::min(pair->first->rbA->bounciness, pair->first->rbB->bounciness);

		sf::Vector2f currentVelocityDifference = pair->first->rbB->currentVelocity - pair->first->rbA->currentVelocity;

		float velAlongNormal = Dot(currentVelocityDifference.x, currentVelocityDifference.y, pair->second->collisionNormal.x,
			pair->second->collisionNormal.y);


		if (velAlongNormal > 0) continue;

		float j = -(1 + minBounce) * velAlongNormal;

		float invMassA, invMassB;
		if (pair->first->rbA->mass == 0)
			invMassA = 0;
		else
			invMassA = 1 / pair->first->rbA->mass;

		if (pair->first->rbB->mass == 0)
			invMassB = 0;
		else
			invMassB = 1 / pair->first->rbB->mass;

		j /= (invMassA + invMassB);

		sf::Vector2f impulse = j * pair->second->collisionNormal;

		// ... update velocities
		pair->first->rbA->currentVelocity = pair->first->rbA->currentVelocity - (invMassA * impulse);
		pair->first->rbB->currentVelocity = pair->first->rbB->currentVelocity + (invMassB * impulse);

		if (std::fabsf(pair->second->penetration) > 0.05f) {

			//PositionalCorrection(pair->first);
		}
	}
}

void PhysicSystem::PositionalCorrection(CollisionPair* c)
{
	const float percent = 0.2f;

	float invMassA, invMassB;
	if (c->rbA->mass == 0)
		invMassA = 0;
	else
		invMassA = 1 / c->rbA->mass;

	if (c->rbB->mass == 0)
		invMassB = 0;
	else
		invMassB = 1 / c->rbB->mass;

	sf::Vector2f correction = ((collisions[c]->penetration / (invMassA + invMassB)) * percent) * -collisions[c]->collisionNormal;

	sf::Vector2f temp = c->rbA->position;
	temp += invMassA * correction;
	c->rbA->position = temp;

	temp = c->rbB->position;
	temp -= invMassB * correction;
	c->rbB->position = temp;
}



void PhysicSystem::UpdatePhysics(float dt)
{

	IntegrateBodies(dt);
	CheckCollisions();
	ResolveCollisions();

}