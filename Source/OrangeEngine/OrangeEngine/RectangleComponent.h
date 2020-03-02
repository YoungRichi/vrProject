#pragma once
#define NOMINMAX
#include "ActorComponent.h"
#include <SFML/Graphics.hpp>
#include "sol.hpp"

class RectangleComponent : public ActorComponent
{
public:
	RectangleComponent(sol::state &_luaPlus);
	RectangleComponent(float w, float h, sf::Color c, sol::state &_luaPlus);
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

