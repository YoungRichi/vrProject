#pragma once
#include <string>
#include "ActorComponent.h"
#include "../sol/sol.hpp"

using namespace std;

class ScriptComponent : public ActorComponent
{
public:
	ScriptComponent(string _fileName, sol::state &_lua);
	~ScriptComponent(void);

	virtual void Update(float dt);

	bool fileLoaded = false;
	sol::state lua;

private:
	string s;
};

