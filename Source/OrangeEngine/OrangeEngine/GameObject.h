#pragma once
#include "GameObjectManager.h"
class GameObject :
	public GameObjectManager
{
public:
	GameObject();
	~GameObject();

	GameObjectManager *scene;
	GameObjectManager *sun;
	GameObjectManager *earth;
	GameObjectManager *moon;
};

