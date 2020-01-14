#include <SFML/Graphics.hpp>
#include "ShapeComponent.h"

ShapeComponent::ShapeComponent()
{
	edge = 10;
	radius = 10;
	color = sf::Color::White;
	componentName = "shape";
}


ShapeComponent::ShapeComponent(float r,float e, sf::Color c)
{
	edge = e;
	radius = r;
	color = c;
	componentName = "shape";
}

void ShapeComponent::SetRadius(float r)
{
	radius = r;
}

void ShapeComponent::SetEdge(float e)
{
	edge = e;
}

float ShapeComponent::GetEdge()
{
	return edge;
}

float ShapeComponent::GetRadius()
{
	return radius;
}

void ShapeComponent::SetColor(sf::Color c)
{
	color = c;
}

sf::Color ShapeComponent::GetColor()
{
	return color;
}
