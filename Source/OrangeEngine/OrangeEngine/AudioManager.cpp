#include "AudioManager.h"

void AudioManager::loadAudio(std::string name,int i)
{
	buffer[i].loadFromFile(name);
}


void AudioManager::setBuffer(int i)
{
	sound[i].setBuffer(buffer[i]);
}

void AudioManager::playAudio(int i)
{
	sound[i].play();
}


void AudioManager::stopPlay(int i)
{
	sound[i].stop();
}

void AudioManager::pauseSound(int i)
{
	sound[i].pause();
}

void AudioManager::setPitch(int i,float pitch)
{
	sound[i].setPitch(pitch);
}

void AudioManager::setVolume(int i,float vol)
{
	sound[i].setVolume(vol);
}

void AudioManager::setLoop(int i,bool tf)
{
	sound[i].setLoop(tf);
}

void AudioManager::setPlayingOffset(int i,float time)
{
	sound[i].setPlayingOffset(sf::seconds(time));
}

