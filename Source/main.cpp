
#include <iostream>
#include "windows.h"
#include <stdio.h>
#include <direct.h>
#include <stdlib.h>
#include <ctype.h>
#include <basetsd.h> 
#include <winnt.h>
#include <tchar.h>
#include "OrangeEngine.h"
#include "LuaPlus.h"
#include "../Actor.h"
#include "../Scene1.h"
#include "SFML\Audio.hpp"
#include <lua.hpp>
#define SOL_ALL_SAFETIES_ON 1
#include "../sol/sol.hpp"

sol::state lua;

int main()
{
	Scene1 ss;

	OrangeEngine* Orange = OrangeEngine::GetInstance();

	lua.open_libraries(sol::lib::base);
	//create an instance of engine 
	// init engine
	//orangeengine.createscene/loadscene (file name/scene name)
	// orangeengine.run

	if (Orange->InitInstance())
	{
	
		//sf::SoundBuffer  buffers;
		//sf::Sound sounds;
		//buffers.loadFromFile("Audio/file_example_WAV_1MG.wav");
		//sounds.setBuffer(buffers);
		//sounds.play();

		//Orange.LoadLevel("SceneXML.xml");
		/*^^^^^^ YOU NEED THIS LINE ^^^^^*/
		ss.buildScene(Orange, lua);
		//Orange->CreateXML();
		Orange->Run();
	}

	return 0;

}