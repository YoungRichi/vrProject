#ifndef __Audio_COMPONENT_H__
#define __Audio_COMPONENT_H__
#include <SFML/Audio.hpp>
#include "ActorComponent.h"


class AudioComponent : public ActorComponent
{
public:
	AudioComponent();
	AudioComponent(std::string c);
	void SetName(std::string soundname); 
	std::string getString() ;
	void playAudio(int i);


private:
	bool play;
	int buffer;
	std::string name;
	std::string soundname;
	std::vector<sf::SoundBuffer> buffers;
	std::vector<sf::Sound> sounds;
};

#endif 
