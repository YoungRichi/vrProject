
#include "AudioComponent.h"


AudioComponent::AudioComponent()
{
}


AudioComponent::~AudioComponent()
{
}

void AudioComponent::loadSound(std::string filePath)
{
	if (filePath == "")
	{
		return;
	}

	soundBuffer.loadFromFile(filePath);

	if (!soundBuffer.loadFromFile(filePath))
		std::cout << "ERROR! Sound file not found." << std::endl;

	sound.setBuffer(soundBuffer);
}

void AudioComponent::playSound()
{
	sound.play();
}

void AudioComponent::pauseSound()
{
	sound.pause();
}

void AudioComponent::LoopSound(bool loop)
{
	sound.setLoop(loop);
}

