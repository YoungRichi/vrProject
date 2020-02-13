#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceHolder.h"
#include "ActorComponent.h"
class AudioManager : public ActorComponent
{
public:
	std::vector<sf::SoundBuffer> buffer;
	std::vector<sf::Sound> sound;
	void loadAudio(std::string name,int i);
	void playAudio(int i);
	void setBuffer(int i);
	void stopPlay(int i);
	void pauseSound(int i);
	void setPitch(int i,float pitch);
	void setVolume(int i,float vol);
	void setLoop(int i,bool tf);
	void setPlayingOffset(int i,float time);
};

