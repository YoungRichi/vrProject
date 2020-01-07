#include "PrinterScriptingComponent.h"
#include "LuaPlus/LuaPlus.h"
#include <iostream>

using namespace LuaPlus;

void PrinterScriptingComponent::InterpretResult(LuaPlus::LuaObject result)
{
	std::cout << result.GetByName("result").GetString() << std::endl;
}

LuaPlus::LuaObject PrinterScriptingComponent::BuildContext(LuaPlus::LuaState* state)
{
	state->DoString("Context = {}");
	auto context = state->GetGlobal("Context");

	context.Set("item", text.c_str());
	return context;
}

PrinterScriptingComponent::PrinterScriptingComponent(std::string text)
	: text(text)
{
}


PrinterScriptingComponent::~PrinterScriptingComponent()
{
}
