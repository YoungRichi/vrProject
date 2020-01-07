#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "ScriptingComponent.h"
class PrinterScriptingComponent :
	public ScriptingComponent
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

