#define NOMINMAX

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

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE previousInstance, PSTR cmdLine, INT nCmdShow)
{
	Scene1 ss;

	OrangeEngine* Orange = OrangeEngine::GetInstance();

	//create an instance of engine 
	// init engine
	//orangeengine.createscene/loadscene (file name/scene name)
	// orangeengine.run

	if (Orange->InitInstance())
	{
		ss.buildScene(Orange);
		Orange->Run();
	}

	return 0;

}