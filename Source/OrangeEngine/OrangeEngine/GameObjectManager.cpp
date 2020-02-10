#include "GameObjectManager.h"
#include"Actor.h"

//oTransform* oT;
//Rigidbody* rb;

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	for (auto a : actors)
		delete a;
}

//void GameObjectManager::SetTransform(float x, float y )
//{
//	tc.translate(x,y);
//}
//
//void GameObjectManager::GetTransform()
//{
//	tc.getMatrix();
//}
//void GameObjectManager::SetMass(float m)
//{
//	m = mass;
//}
//
//float GameObjectManager::GetMass()
//{
//	return mass;
//}
//Transform GameObjectManager::getWorldTransform() const
//{
//	sf::Transform transform = sf::Transform::Identity;
//
//	//for (const GameObjectManager* node = this; node != nullptr; node = node->parent)
//	//	transform = node->GetTransform() * transform;
//
//	return worldTransform;
//}


//
//sf::Vector2f GameObjectManager::GetPosition() const
//{
//	return oT->GetLocation();
//}
//
//void GameObjectManager::AddChild(GameObjectManager* s)
//{
//	children.push_back(s);
//	s->parent = this;
//}

Actor * GameObjectManager::GetActor(GUID id) const
{
	for (auto actor : actors)
		if (actor->Id() == id)
			return actor;
}

void GameObjectManager::AddActor(Actor * actor)
{
	actors.push_back(actor);
}

void GameObjectManager::RemoveActor(GUID id)
{
	for (auto i = actors.begin(); i != actors.end(); ++i)
		if ((*i)->Id() == id)
		{
			actors.erase(i);
			return;
		}
}

void GameObjectManager::Update(float msec)
{
	//if (parent)
	//{
	//	worldTransform = parent->worldTransform * transform;
	//}
	//else
	//{
	//	worldTransform = transform;
	//}
	//for (std::vector<GameObjectManager*>::iterator i = children.begin(); i != children.end(); ++i)
	//{
	//	(*i)->Update(msec);
	//}

	//rb->Integrate(sf::Time dT);
}
