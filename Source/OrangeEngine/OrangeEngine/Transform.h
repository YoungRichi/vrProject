#include "SFML/Graphics/Transform.hpp"
#include "SFML/System/Vector2.hpp"
#ifndef __TRANSFORM_COMPONENT_H__
#define __TRANSFORM_COMPONENT_H__

#include "ActorComponent.h"
class Transform : public ActorComponent {
public:
	Transform();
	Transform(sf::Vector2<float> trans);
	Transform(sf::Vector2<float> trans, float angle, sf::Vector2<float> scal);
	void Translate(float x, float y);
	void Rotate(float angle);
	void Scale(float x, float y);
	sf::Vector2<float> GetLocation();
	float GetRotation();
	sf::Vector2<float> GetScale();
	sf::Transform translate;
	sf::Transform rotation;
	sf::Transform scale;
	sf::Transform transform;
private:
	void UpdateTransform();

	sf::Vector2<float> translationv;
	float rotationv;
	sf::Vector2<float> scalev;
};

#endif __TRANSFORM_COMPONENT_H__

