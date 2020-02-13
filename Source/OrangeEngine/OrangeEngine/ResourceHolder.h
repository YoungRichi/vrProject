#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.h"

class ResourceHolder
{
public:
	static ResourceHolder& get();

	ResourceManager<sf::Font>           fonts;
	ResourceManager<sf::Texture>        textures;
	ResourceManager<sf::SoundBuffer>    soundBuffers;

private:
	ResourceHolder();
};