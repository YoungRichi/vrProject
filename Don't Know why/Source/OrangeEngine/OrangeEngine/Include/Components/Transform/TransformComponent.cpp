#include "TransformComponent.h"



TransformComponent::TransformComponent()
{
	Transform.scale(1.0f, 1.0f);
}
TransformComponent::~TransformComponent()
{
}

sf::Vector2f TransformComponent::getPosition()
{
	return Transform.getPosition();
}

sf::Transformable* TransformComponent::GetTransform()
{
	return &Transform;
}

sf::Transform TransformComponent::getWorldTransform()
{
	return WorldTransform;
}

void TransformComponent::setWorldTransform(sf::Transform worldTransform)
{
	WorldTransform = worldTransform;
}

void TransformComponent::setPosition(sf::Vector2f x)
{
	Transform.setPosition(x);
}

void TransformComponent::rotate(float a)
{
	Transform.rotate(a);
}

void TransformComponent::move(sf::Vector2f m)
{
	Transform.move(m);
}

void TransformComponent::Update(sf::Time dt, sf::Transform *parentWorldTransform)
{
	if (parentWorldTransform)
	{
		setWorldTransform(*parentWorldTransform * Transform.getTransform());
	}
	else
	{
		setWorldTransform(Transform.getTransform());
	}

	//rotate(dt.asSeconds() * 100.0f);
}