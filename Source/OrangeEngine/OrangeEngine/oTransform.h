#ifndef __TRANSFORM_COMPONENT_H__
#define __TRANSFORM_COMPONENT_H__

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "ActorComponent.h"


class oTransform : public ActorComponent {
public:
	oTransform();
	oTransform(sf::Vector2<float> trans);
	oTransform(sf::Vector2<float> trans, float angle, sf::Vector2<float> scal);
	~oTransform();
	void Translate(float x, float y);
	void Rotate(float angle);
	void Scale(float x, float y);
	sf::Transformable* GetTransform() { return transform; }
	void SetTransform(sf::Transformable* tr) { transform = tr; }
	sf::Vector2<float> GetLocation();
	float GetRotation();
	sf::Vector2<float> GetScale();
	sf::FloatRect GetGlobalBounds();

	sf::Transformable* transform;


	//sf::Transform translate;
	//sf::Transform rotation;
	//sf::Transform scale;
	//sf::Transform transform;
private:
	void UpdateTransform();

	//sf::Vector2<float> translationv;
	//float rotationv;
	//sf::Vector2<float> scalev;
};

#endif __TRANSFORM_COMPONENT_H__

