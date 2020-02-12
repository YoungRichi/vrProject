#include "oTransform.h"
#include"Actor.h"
#include"ShapeComponent.h"
#include "RectangleComponent.h"

oTransform::oTransform()
{
	transform = new sf::Transformable();
	//transforms
	transform->setPosition(0, 0);
	transform->setRotation(0);
	transform->setScale(1, 1);
	//transform->scale(10, 10);
	//user values (vector, angle in degrees, vector)
	//translationv = sf::Vector2<float>(0, 0);
	//rotationv = 0;
	//scalev = sf::Vector2<float>(0, 0);
	//updating the main matrix
	//transform = translate * rotation * scale;
	//transform = scale * rotation * translate;
	componentName = "transformComponent";
}
oTransform::oTransform(sf::Vector2<float> trans)
{
	transform = new sf::Transformable();

	transform->setPosition(trans.x, trans.y);
	transform->setRotation(0);
	transform->setScale(0, 0);
//	translationv = sf::Vector2<float>(trans.x, trans.y);
	//rotationv = 0;
	//scalev = sf::Vector2<float>(0, 0);
	//transform = translate * rotation * scale;
	componentName = "transformComponent";
}
oTransform::oTransform(sf::Vector2<float> trans, float angle, sf::Vector2<float> scal)
{
	transform = new sf::Transformable();

	transform->setPosition(trans.x, trans.y);
	transform->setRotation(angle);
	transform->setScale(scal.x, scal.y);
	//translationv = sf::Vector2<float>(trans.x, trans.y);
	//rotationv = angle;
	//scalev = sf::Vector2<float>(scal.x, scal.y);
	//transform = translate * rotation * scale;
	//transform = scale * rotation * translate;
	componentName = "transformComponent";
}

oTransform::~oTransform()
{
	if (transform)
		delete transform;
}

void oTransform::Translate(float x, float y)
{
	transform->move(x, y);
	//translationv += sf::Vector2<float>(x, y);
	//UpdateTransform();
}
void oTransform::Rotate(float angle)
{
	transform->rotate(angle);
	//rotationv += angle;
	//UpdateTransform();
}
void oTransform::Scale(float x, float y)
{
	transform->scale(x, y);
	//scalev += sf::Vector2<float>(x, y);
	//UpdateTransform();
}
sf::Vector2<float> oTransform::GetLocation()
{
	return transform->getPosition();
}
float oTransform::GetRotation()
{
	return transform->getRotation();
}
sf::Vector2<float> oTransform::GetScale()
{
	return transform->getScale();
}
sf::FloatRect oTransform::GetGlobalBounds()
{
	if (GetActor()->GetComponent("shape"))
	{
		ShapeComponent* sc = (ShapeComponent*)GetActor()->GetComponent("shape");
		sf::CircleShape shape(sc->GetRadius(), sc->GetEdge());
		return shape.getGlobalBounds();
	}
	else if (GetActor()->GetComponent("rect"))
	{
		RectangleComponent* r = (RectangleComponent*)GetActor()->GetComponent("rect");
		sf::RectangleShape shape;
		shape.setSize(sf::Vector2f(r->GetWidth(), r->GetHeight()));
		return shape.getGlobalBounds();
	}
	return sf::FloatRect();
}
void oTransform::UpdateTransform()
{
	//transform = translate * rotation * scale;

}
