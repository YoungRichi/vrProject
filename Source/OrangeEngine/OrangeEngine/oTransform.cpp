#include "oTransform.h"

oTransform::oTransform()
{
	//transforms
	translate.translate(0, 0);
	rotation.rotate(0);
	scale.scale(1, 1);
	//user values (vector, angle in degrees, vector)
	translationv = sf::Vector2<float>(0, 0);
	rotationv = 0;
	scalev = sf::Vector2<float>(0, 0);
	//updating the main matrix
	transform = translate * rotation * scale;
	//transform = scale * rotation * translate;
	componentName = "transformComponent";
}
oTransform::oTransform(sf::Vector2<float> trans)
{

	translate.translate(trans.x, trans.y);
	rotation.rotate(0);
	scale.scale(0, 0);
	translationv = sf::Vector2<float>(trans.x, trans.y);
	rotationv = 0;
	scalev = sf::Vector2<float>(0, 0);
	transform = translate * rotation * scale;
	componentName = "transformComponent";
}
oTransform::oTransform(sf::Vector2<float> trans, float angle, sf::Vector2<float> scal)
{
	translate.translate(trans.x, trans.y);
	rotation.rotate(angle);
	scale.scale(scal.x, scal.y);
	translationv = sf::Vector2<float>(trans.x, trans.y);
	rotationv = angle;
	scalev = sf::Vector2<float>(scal.x, scal.y);
	transform = translate * rotation * scale;
	//transform = scale * rotation * translate;
	componentName = "transformComponent";
}

void oTransform::Translate(float x, float y)
{
	translate.translate(x, y);
	translationv += sf::Vector2<float>(x, y);
	UpdateTransform();
}
void oTransform::Rotate(float angle)
{
	rotation.rotate(angle);
	rotationv += angle;
	UpdateTransform();
}
void oTransform::Scale(float x, float y)
{
	scale.scale(x, y);
	scalev += sf::Vector2<float>(x, y);
	UpdateTransform();
}
sf::Vector2<float> oTransform::GetLocation()
{
	return translationv;
}
float oTransform::GetRotation()
{
	return rotationv;
}
sf::Vector2<float> oTransform::GetScale()
{
	return scalev;
}
void oTransform::UpdateTransform()
{
	transform = translate * rotation * scale;

}
