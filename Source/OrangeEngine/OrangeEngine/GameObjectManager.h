#pragma once
#include <SFML/Graphics.hpp>

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

	Transform getWorldTransform() const;

	void AddChild(GameObjectManager* s);

	void Update(float msec);

protected:
	GameObjectManager* parent;
	Transform worldTransform;
	Transform transform;
	std::vector<GameObjectManager*> children;
};

