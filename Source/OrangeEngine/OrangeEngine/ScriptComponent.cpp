#include "ScriptComponent.h"
using namespace std;

//ScriptComponent::ScriptComponent()


ScriptComponent::ScriptComponent(string _fileName, sol::state &_lua)
{
	componentName = "ScriptComponent";
	_lua.script_file(_fileName);
}

ScriptComponent::~ScriptComponent(void)
{
}

void ScriptComponent::Update(float dt)
{
}