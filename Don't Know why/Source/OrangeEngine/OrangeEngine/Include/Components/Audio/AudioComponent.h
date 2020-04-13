#pragma once
#include "../BaseComponent.h"
enum class Sound_ID
{
	Sound_By
};

class AudioComponent : public BaseComponent
{
public:
	AudioComponent();
	~AudioComponent();

	void loadSound(std::string filePath);
	void playSound();
	void pauseSound();
	void LoopSound(bool loop);

protected:

private:
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;
};


