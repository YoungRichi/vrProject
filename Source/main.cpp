#include <SFML/Graphics.hpp>
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
#include "OrangeEngine/OrangeEngine/ScriptingComponent.h"
#include "OrangeEngine/OrangeEngine/ShapeComponent.h"
#include "OrangeEngine/OrangeEngine/Transform.h"
#include "OrangeEngine/OrangeEngine/SplashScreen.h"



int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE previousInstance, PSTR cmdLine, INT nCmdShow)
{
	OrangeEngine* Orange = OrangeEngine::GetInstance();
	if (Orange->InitInstance(hInstance, previousInstance, cmdLine, nCmdShow, "Orange Engine"))
	{
		
		Actor* sun = new Actor();
		sun->AddComponent(new ShapeComponent(10,20, sf::Color::Red));
		sun->tc->Translate(200, 200);
		sun->tc->Scale(10, 10);
		
		Actor* moon = new Actor();
		moon->AddComponent(new ShapeComponent(10,4,sf::Color::Blue));
		moon->tc->Translate(-10, 10);
		moon->tc->Scale(0.3, 0.3);
		sun->AddChild(moon);
		sun->tc->Translate(300, 200);
		//sun->tc->Rotate(90);
		
		Actor* star = new Actor();
		star->AddComponent(new ShapeComponent(10, 5, sf::Color::Yellow));
		star->tc->Translate(-10, 10);
		star->tc->Scale(0.5, 0.5);
		moon->AddChild(star);
		//moon->tc->Translate(300, 200);

		Orange->AddActor(sun);
		Orange->AddActor(moon);
		Orange->AddActor(star);

		Orange->Run();
		delete(sun);
	}
	return 0;

}