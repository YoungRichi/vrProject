#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "LuaPlus/LuaPlus.h"
#include <string>


class ScriptingComponent
{
private:

	LuaPlus::LuaState* pLuaState;

protected:
	virtual void InterpretResult(LuaPlus::LuaObject result) = 0;
	virtual LuaPlus::LuaObject BuildContext(LuaPlus::LuaState* state) = 0;

public:
	void runScript(const std::string& name);

	ScriptingComponent();
	virtual ~ScriptingComponent();
};

