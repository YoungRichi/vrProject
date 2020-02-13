//#include "SFML/Graphics/Transform.hpp"
#define NOMINMAX
#include <SFML/Graphics.hpp>
#include "oTransform.h"
#include "Actor.h"
#include "oRigidbody.h"
#include <windows.h>
#include "oInputManager.h"

Actor::Actor(oTransform* trns, oRigidBody* rb)
	: transform(trns)
	, rb(rb)
{
	CoCreateGuid(&id);
	parent = NULL;

	transform->SetActor(this);
	this->rb->SetActor(this);
	//position = new oTransform();
	//worldTransform = new sf::Transform();
	//rb = new oRigidBody();
	//localTransform = &(position->transform);
}

Actor::~Actor(void)
{
	for (unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
	if (transform)
		delete transform;
	if (rb)
		delete rb;

	for (auto c : components)
		if (c)
			delete c;
}

void Actor::AddComponent(ActorComponent* component)
{
	components.push_back(component);
	component->SetActor(this);
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

void Actor::SetTransform(oTransform * transform)
{
	if (this->transform && transform != this->transform)
		delete this->transform;

	this->transform = transform;
}

sf::Transformable* Actor::GetWorldTransform()
{
	return transform->GetTransform();
}

//void Actor::SetTransform(sf::Transform matrix)
//{
//	//*localTransform = matrix;
//}

void Actor::AddChild(Actor* s)
{
	children.push_back(s);
	s->SetParent(this);
}

void Actor::Update(float msec)
{
	if (parent)
	{ //This node has a parent...
		//*worldTransform = *(parent->worldTransform) * *(localTransform);
	}
	else
	{ //Root node, world transform is local transform!
		//worldTransform = localTransform;
	}
	/*for (vector<Actor*>::iterator i = children.begin(); i != children.end(); ++i)
	{
		(*i)->Update(msec);
	}*/
	//if (inputSystem.GetKey("d"))
	//	this->GetTransform()->Translate(10, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->GetTransform()->Translate(10, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->GetTransform()->Translate(-10, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->GetTransform()->Translate(0, -10);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->GetTransform()->Translate(0, 10);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		//exit(0);
	}
}

void Actor::Audio(std::string string)
{
	sf::SoundBuffer buffer;
	sf::Sound sound;

	buffer.loadFromFile(string);
	sound.setBuffer(buffer);
	sound.play();
}

