#pragma once
#include <SFML/Graphics/Transform.hpp>
#include <SFML/System/Vector2.hpp>
#include "Transform.h"
#include "ActorComponent.h"


class Rigidbody : public ActorComponent
{
public:
	Rigidbody();
	~Rigidbody();
	void AddForce(sf::Vector2<float> direction);
	void Integrate(float dT);
private:
	sf::Vector2<float> currentVelocity;
	sf::Vector2<float> acceleration;
	sf::Vector2<float> totalForces;
};

