#ifndef __BASE_ACTOR_H__
#define __BASE_ACTOR_H__
#define NOMINMAX

#include <SFML/Graphics.hpp>
#include "ActorComponent.h"
#include "oRigidBody.h"
#include <string>
#include <windows.h>
#include <vector>


using namespace std;
namespace sf
{
	class Transform;
}
class oTransform;
class oRigidBody;
class oInputManager;

class Actor
{
private:
	GUID id;
	vector<ActorComponent*> components;

public:
	Actor(oTransform* trns, oRigidBody* rb = nullptr);
	~Actor(void);
	void AddComponent(ActorComponent* component);
	ActorComponent* GetComponent(string componentName);
	//void SetTransform(sf::Transform matrix);
	void SetTransform(oTransform* transform);
	//sf::Transform* GetLocalTransform() { return localTransform; }
	sf::Transformable* GetWorldTransform();
	void SetParent(Actor* p) { parent = p; }
	void AddChild(Actor* s);
	virtual void Update(float msec);
	void SetObeysGravity(bool value) { rb->SetObeysGravity(value); }
	void SetMass(float value) { rb->SetMass(value); }

	oTransform* GetTransform() { return transform; }
	oRigidBody* GetRigidbody() { return rb; }
	oInputManager* GetInput() { return input; }

	GUID Id() const { return id; }
protected:
	oTransform* transform;
	oRigidBody* rb;
	oInputManager* input;

	Actor* parent;
	//sf::Transform* worldTransform;
	//sf::Transform* localTransform;
	vector<Actor*> children;
};

#endif