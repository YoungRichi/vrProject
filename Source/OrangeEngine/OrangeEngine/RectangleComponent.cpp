#include "RectangleComponent.h"
#define NOMINMAX



RectangleComponent::RectangleComponent(sol::state &_luaPlus)
	: width(100)
	, height(10)
	, color(sf::Color::White)
{
	componentName = "rect";
	width = 0.f;
	height  = 0.f;


	_luaPlus.set("Transform", this);

	_luaPlus["GetWidth"] = &RectangleComponent::GetWidth;
	_luaPlus["SetWidth"] = &RectangleComponent::SetWidth;

	_luaPlus["GetHeight"] = &RectangleComponent::GetHeight;
	_luaPlus["SetHeight"] = &RectangleComponent::SetHeight;
}

RectangleComponent::RectangleComponent(float w, float h, sf::Color c, sol::state &_luaPlus)
	: width(w)
	, height(h)
	, color(c)
{
	componentName = "rect";
}

void RectangleComponent::SetWidth(float w)
{
	width = w;
}

void RectangleComponent::SetHeight(float h)
{
	height = h;
}

float RectangleComponent::GetWidth() const
{
	return width;
}

float RectangleComponent::GetHeight() const
{
	return height;
}

void RectangleComponent::SetColor(sf::Color c)
{
	color = c;
}

sf::Color RectangleComponent::GetColor() const
{
	return color;
}

