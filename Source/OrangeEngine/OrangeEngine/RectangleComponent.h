#pragma once
#define NOMINMAX
#include "ActorComponent.h"
#include <SFML/Graphics.hpp>


class RectangleComponent : public ActorComponent
{
public:
	RectangleComponent();
	RectangleComponent(float w, float h, sf::Color c);
	void SetWidth(float w);
	void SetHeight(float h);
	float GetWidth() const;
	float GetHeight() const;
	void SetColor(sf::Color c);
	sf::Color GetColor() const;

private:
	float width;
	float height;
	sf::Color color;
};

