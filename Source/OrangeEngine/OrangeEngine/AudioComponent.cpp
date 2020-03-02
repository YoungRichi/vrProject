#include "AudioComponent.h"
using namespace std;

AudioComponent::AudioComponent()
{
	componentName = "AudioComponent";

}

AudioComponent::AudioComponent(string fileToSet)
{
	componentName = "AudioComponent";
	setAudio(fileToSet);
}

AudioComponent::~AudioComponent(void)
{
}

void AudioComponent::Update(float dt)
{
}

void AudioComponent::setAudio(string fileToSet)
{
	if (!audioFile.openFromFile(fileToSet))
	{
		fileLoaded = false;
		return;
	}

	fileLoaded = true;
}

void AudioComponent::PlayAudio()
{
	if (fileLoaded)
	{
		audioFile.play();
	}
}
