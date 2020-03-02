#ifndef __BASE_ACTOR_COMPONENT_H__
#define __BASE_ACTOR_COMPONENT_H__
#include <string>
#include <windows.h>

using namespace std;

class Actor;

class ActorComponent
{
private:
	Actor* actor;

public:
	GUID id;
	string componentName;
	
	ActorComponent();
	Actor* GetActor() { return actor; }
	void SetActor(Actor* a) { actor = a; }


};

#endif 
