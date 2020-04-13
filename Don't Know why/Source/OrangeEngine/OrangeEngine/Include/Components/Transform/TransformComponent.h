#pragma once
#include "../BaseComponent.h"

class TransformComponent : public BaseComponent
{
public:
	TransformComponent();
	~TransformComponent();

	sf::Vector2f getPosition();
	sf::Transformable *GetTransform();
	sf::Transform getWorldTransform();

	void setWorldTransform(sf::Transform worldTransform);
	void setPosition(sf::Vector2f z);
	void rotate(float a);//a is angle
	void move(sf::Vector2f m);

	void Update(sf::Time dt, sf::Transform *parentWorldTransform = nullptr);


private:
	sf::Transformable Transform;
	sf::Transform WorldTransform;
};

