#ifndef __SHAPE_COMPONENT_H__
#define __SHAPE_COMPONENT_H__
#include "ActorComponent.h"

namespace sf {
	class Color;

}

class ShapeComponent : public ActorComponent
{
public:
	ShapeComponent();
	ShapeComponent(float r, float e, sf::Color c);
	void SetRadius(float r);
	void SetEdge(float e);
	float GetRadius();
	float GetEdge();
	void SetColor(sf::Color c);
	sf::Color GetColor();

private:
	float radius;
	float edge;
	sf::Color color;
};

#endif 
