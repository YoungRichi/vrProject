#ifndef __BASE_ACTOR_H__
#define __BASE_ACTOR_H__
#include <string>
#include <windows.h>
#include "ActorComponent.h"
#include <vector>
using namespace std;
namespace sf
{
	class Transform;
}
class Transform;

class Actor
{
private:
	GUID id;
	vector<ActorComponent*> components;

public:
	Actor();
	~Actor(void);
	void AddComponent(ActorComponent* _component);
	ActorComponent* GetComponent(string componentName);
	void SetTransform(sf::Transform matrix);
	sf::Transform* GetLocalTransform() { return localTransform; }
	sf::Transform* GetWorldTransform() { return worldTransform; }
	void SetParent(Actor* p) { parent = p; }
	void AddChild(Actor* s);
	virtual void Update(float msec);
	Transform* tc;

protected:
	Actor* parent;
	sf::Transform* worldTransform;
	sf::Transform* localTransform;
	vector<Actor*> children;
};

#endif