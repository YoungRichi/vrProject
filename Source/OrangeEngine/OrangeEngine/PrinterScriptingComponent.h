#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "ScriptingSystem.h"
class PrinterScriptingComponent :
	public ScriptingSystem
{
private:
	std::string text;

protected:
	virtual void InterpretResult(LuaPlus::LuaObject result);
	virtual LuaPlus::LuaObject BuildContext(LuaPlus::LuaState* state);

public:
	PrinterScriptingComponent(std::string text);
	virtual ~PrinterScriptingComponent();
};

