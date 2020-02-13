#include <SFML/Graphics.hpp>
#include "AudioComponent.h"

AudioComponent::AudioComponent()
{
	soundname = "";
	componentName = "audio";
}


AudioComponent::AudioComponent(std::string c)
{
	soundname = c;
	componentName = "audio";

}


void AudioComponent::SetName(std::string s)
{
	soundname = s;
}

std::string AudioComponent::getString()
{
	return soundname;
}


