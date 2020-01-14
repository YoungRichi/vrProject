#ifndef __BASE_ACTOR_COMPONENT_H__
#define __BASE_ACTOR_COMPONENT_H__
#include <string>
#include <windows.h>

using namespace std;

class ActorComponent
{
public:
	GUID id;
	string componentName;
};

#endif 
