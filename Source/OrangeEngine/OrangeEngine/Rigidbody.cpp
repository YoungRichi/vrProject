#include "Rigidbody.h"
#include "../../OrangeEngine.h"
#include "../GameObjectManager.h"
 

GameObjectManager* gm;


Rigidbody::Rigidbody()
{
}


Rigidbody::~Rigidbody()
{
}

void Rigidbody::AddForce(sf::Vector2<float> force)
{
	totalForces += force;
}

void Rigidbody::Integrate(float dT) {

	/*if (obeysGravity && !IsGrounded()) {
		acceleration = gravity;
	}
	else {
		if (Mathf.Abs(currentVelocity.y) < 0.05f)
			currentVelocity.y = 0;
	}*/

	acceleration += totalForces / gm->mass;
	if (gm->mass == 0)
		acceleration = sf::Vector2f (0,0);

	currentVelocity += acceleration * dT;

	sf::Vector2f temp = gm->GetPosition();
	temp += currentVelocity * dT;
	gm->GetPosition() = temp;
	//SetAABB();

	totalForces = sf::Vector2f(0, 0);
}
