//#include "SFML/Graphics/Transform.hpp"
#include "oTransform.h"
#include "Actor.h"
#include "oRigidbody.h"
#include <windows.h>

Actor::Actor()
{
	CoCreateGuid(&id);
	parent = NULL;
	position = new oTransform();
	worldTransform = new sf::Transform();
	rb = new oRigidBody();
	localTransform = &(position->transform);
}

Actor::~Actor(void)
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

void Actor::AddComponent(ActorComponent* _component)
{
	components.push_back(_component);
}

ActorComponent* Actor::GetComponent(string componentName)
{
	vector<ActorComponent*>::iterator it;
	for (it = components.begin(); it != components.end(); it++)
	{
		if ((*it)->componentName == componentName)
		{
			return *it;
		}
	}
	return NULL;
}

void Actor::SetTransform(sf::Transform matrix)
{
	*localTransform = matrix;
}

void Actor::AddChild(Actor* s)
{
	children.push_back(s);
	s->SetParent(this);
}

void Actor::Update(float msec)
{
	if (parent)
	{ //This node has a parent...
		*worldTransform = *(parent->worldTransform) * *(localTransform);
	}
	else
	{ //Root node, world transform is local transform!
		worldTransform = localTransform;
	}
	/*for (vector<Actor*>::iterator i = children.begin(); i != children.end(); ++i)
	{
		(*i)->Update(msec);
	}*/
}
