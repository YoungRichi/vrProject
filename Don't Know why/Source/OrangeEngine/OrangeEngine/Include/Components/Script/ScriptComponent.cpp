#include "../../Unity/Unity.h"
#include "ScriptComponent.h"
#include <fstream>



ScriptComponent::ScriptComponent()
{
	lua.open_libraries(sol::lib::base);
}


ScriptComponent::~ScriptComponent()
{
}

void  ScriptComponent::SetScriptName(std::string script)
{
	scriptName = script;
}

float ScriptComponent::RunScript(std::string functionName, float mass, float height)
{
	lua.script_file(scriptName);
	sol::protected_function funcName = lua[functionName];

	sol::protected_function_result result = funcName(mass, height);
	if (result.valid())
	{
		float c = result;

		return c;
	}
	return 0;
}

bool  ScriptComponent::RunScript(std::string functionName, float objectPosX)
{
	lua.script_file(scriptName);
	sol::protected_function funcName = lua[functionName];

	sol::protected_function_result result = funcName(objectPosX);
	if (result.valid())
	{
		bool outOfView = result;

		return outOfView;
	}
	return false;
}
