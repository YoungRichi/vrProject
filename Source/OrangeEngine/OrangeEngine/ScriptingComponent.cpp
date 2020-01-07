#include "ScriptingComponent.h"

using namespace LuaPlus;

void ScriptingComponent::runScript(const std::string & name)
{
	//Buil Context
	LuaObject table = BuildContext(pLuaState);
	//Add context to State
	pLuaState->DoFile(name.c_str());
	LuaFunctionVoid Init = pLuaState->GetGlobal("Init");
	Init(table);
	//run actioc
	LuaFunctionVoid Action = pLuaState->GetGlobal("Action");
	Action();
	//interpret result
	InterpretResult(pLuaState->GetGlobal("Result"));
}

ScriptingComponent::ScriptingComponent()
{
	pLuaState = LuaState::Create();
}


ScriptingComponent::~ScriptingComponent()
{
	LuaState::Destroy(pLuaState);
}
