#pragma once
#include <SFML/Graphics.hpp>
#include "oTransform.h"
#include "Rigidbody.h"

using namespace sf;




class GameObjectManager
{
	sf::Transform tc;
	//sf::Time::asMilliseconds();
public:
	GameObjectManager();
	~GameObjectManager();
	
	void SetTransform(float x, float y);

	void GetTransform();

	void SetMass(float m);

	float GetMass();

	sf::Transform getWorldTransform() const;


	float mass = 1.0f;

	sf::Vector2f GetPosition() const;
	
	void AddChild(GameObjectManager* s);

	void Update(float msec);

protected:
	GameObjectManager* parent;
	sf::Transform worldTransform;
	sf::Transform transform;
	std::vector<GameObjectManager*> children;

};

