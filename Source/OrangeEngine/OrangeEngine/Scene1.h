#pragma once
#include <SFML/System/Time.hpp>
#include "SFML/Audio.hpp"
#include <lua.hpp>
#include "../../OrangeEngine.h"
#define SOL_ALL_SAFETIES_ON 1
#include "../sol/sol.hpp"

class Scene1
{

public:
	Scene1();
	~Scene1();
	void buildScene(OrangeEngine* Orange);
	sol::state lua;
	void update(sf::Time dt);
};

