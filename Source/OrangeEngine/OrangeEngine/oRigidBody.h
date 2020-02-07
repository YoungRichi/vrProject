#pragma once
#include "SFML/Graphics/Transform.hpp"
#include "SFML/System/Vector2.hpp"
#include "oTransform.h"
#include "ActorComponent.h"


class oRigidBody :public ActorComponent
{
public:
	oRigidBody();
	~oRigidBody();
	void AddForce(sf::Vector2<float> direction);
	void Integrate(float dT);
private:
	sf::Vector2<float> currentVelocity;
	sf::Vector2<float> acceleration;
	sf::Vector2<float> totalForces;
};

