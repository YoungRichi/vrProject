#include "SFML/Graphics/Transform.hpp"
#include "SFML/System/Vector2.hpp"


#pragma once
class Rigidbody
{
public:
	Rigidbody();
	~Rigidbody();
	void AddForce(sf::Vector2<float> direction);


private:
	sf::Vector2<float> currentVelocity;
	sf::Vector2<float> acceleration;
};

