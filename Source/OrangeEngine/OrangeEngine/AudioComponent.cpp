#include <SFML/Graphics.hpp>
#include "AudioComponent.h"

AudioComponent::AudioComponent()
{
	buffer = 1;
	soundname = "";
	play = true;
	componentName = "audio";
}


AudioComponent::AudioComponent(int b, std::string c, bool p)
{
	buffer = b;
	soundname = c;
	play = p;
	componentName = "audio";

}

void AudioComponent::SetBuffer(int b)
{
	buffer = b;
	buffers[buffer].loadFromFile(soundname);
	sounds[buffer].setBuffer(buffers[buffer]);
}

float AudioComponent::GetBuffer()
{
	return buffer;
}

void AudioComponent::SetPlay(bool p)
{
	play = p;
	sounds[buffer].play();
}

bool AudioComponent::getPlay()
{
	return play;
}

void AudioComponent::SetName(std::string s)
{
	soundname = s;
}

std::string AudioComponent::getString()
{
	return soundname;
}

void AudioComponent::playAudio(int i)
{
	sounds[i].play();
}

