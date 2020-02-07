#include "oRigidbody.h"
#include "../../OrangeEngine.h"
#include "../GameObjectManager.h"


GameObjectManager* gm;


oRigidBody::oRigidBody()
{
}


oRigidBody::~oRigidBody()
{
}

void oRigidBody::AddForce(sf::Vector2<float> force)
{
	totalForces = sf::Vector2f(111, 1);// += force;
}

void oRigidBody::Integrate(float dT) {
	/*if (obeysGravity && !IsGrounded()) {
		acceleration = gravity;
	}
	else {
		if (Mathf.Abs(currentVelocity.y) < 0.05f)
			currentVelocity.y = 0;
	}*/
	float mass = 1.0f;
	//if (mass == NULL)
	//	return;
		//acceleration += totalForces / mass;
		acceleration = sf::Vector2f(10,1);
	if (mass == 0)
		acceleration = sf::Vector2f(0, 0);

	currentVelocity += acceleration * dT;

	sf::Vector2f temp = gm->GetPosition();
	temp += currentVelocity * dT;
	gm->GetPosition() = temp;
	//SetAABB();

	totalForces = sf::Vector2f(0, 0);
}
