#pragma once
#include <SFML/System/Time.hpp>
#include "../../OrangeEngine.h"


class Scene1
{

public:
	Scene1();
	~Scene1();
	void buildScene(OrangeEngine* Orange);

	void update(sf::Time dt);
};

