#ifndef __SCRIPT_SYSTEM_H__
#define __SCRIPT_SYSTEM_H__
#include <vector>
#include "Actor.h"
#include "../OrangeEngine/ScriptComponent.h"
#include "LuaPlus.h"
#include "../../OrangeEngine.h"
using namespace LuaPlus;

class ScriptingComponent
{
public:
	ScriptingComponent(vector<Actor*>* _actors);
	~ScriptingComponent();
	void Run();

private:
	vector<Actor*>* actors;
	LuaState* pLuaState;
};

#endif
