#pragma once
#define SOL_CHECK_ARGUMENTS 1
#include "../../Unity/Unity.h"
#include <sol.hpp>
#include "../BaseComponent.h"


class ScriptComponent : public BaseComponent
{

public:
	ScriptComponent();
	~ScriptComponent();


	void  SetScriptName(std::string scriptName);
	float RunScript(std::string functionName, float mass, float height);
	bool  RunScript(std::string functionName, float objectPosX);

	//std::vector<std::string> scriptNames;

private:
	sol::state lua;
	std::string scriptName;
};

