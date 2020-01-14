#include "ScriptingSystem.h"



ScriptingSystem::ScriptingSystem(vector<Actor*>* _actors)
{
	actors = _actors;
	pLuaState = LuaState::Create();
}

ScriptingSystem::~ScriptingSystem()
{
	LuaState::Destroy(pLuaState);
	pLuaState = NULL;
}

void ScriptingSystem::Run()
{
	vector<Actor*>::iterator it;
	for (it = actors->begin(); it != actors->end(); it++)
	{
		ActorComponent* ac = (*it)->GetComponent("ScriptComponent");
		if (ac)
		{
			ScriptComponent* sc2 = (ScriptComponent*)ac;
			pLuaState->DoFile(sc2->GetPath().c_str());
			LuaObject table = pLuaState->GetGlobals().GetByName("birthdayList");
			for (LuaTableIterator it(table); it; it.Next())
			{
				LuaObject key = it.GetKey();
				LuaObject value = it.GetValue();
				OrangeEngine::GetInstance()->Print(value.GetString());
				OrangeEngine::GetInstance()->PrintToWindow(value.GetString());
			}
		}
	}
}