#include "ScriptComponent.h"

ScriptComponent::ScriptComponent(string _path)
{
	path = _path;
	componentName = "ScriptComponent";
	CoCreateGuid(&id);
}

string ScriptComponent::GetPath()
{
	return path;
}