#include "GameObjectManager.h"



GameObjectManager::GameObjectManager()
{
}


GameObjectManager::~GameObjectManager()
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
	
}

void GameObjectManager::SetTransform(float x, float y )
{
	tc.translate(x,y);
}

void GameObjectManager::GetTransform()
{
	tc.getMatrix();
}
Transform GameObjectManager::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;

	//for (const GameObjectManager* node = this; node != nullptr; node = node->parent)
	//	transform = node->GetTransform() * transform;

	return worldTransform;
}

void GameObjectManager::AddChild(GameObjectManager* s)
{
	children.push_back(s);
	s->parent = this;
}

void GameObjectManager::Update(float msec)
{
	if (parent)
	{
		worldTransform = parent->worldTransform * transform;
	}
	else
	{
		worldTransform = transform;
	}
	for (std::vector<GameObjectManager*>::iterator i = children.begin(); i != children.end(); ++i)
	{
		(*i)->Update(msec);
	}
}
