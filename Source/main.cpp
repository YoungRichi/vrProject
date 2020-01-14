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
		sun->position->Translate(100, 100);
		sun->position->Scale(10, 10);
		
		Actor* moon = new Actor();
		moon->AddComponent(new ShapeComponent(10,4,sf::Color::Blue));
		moon->position->Translate(50, 10);
		moon->position->Scale(0.3, 0.3);
		sun->AddChild(moon);
		sun->position->Translate(200, 200);
		//sun->tc->Rotate(90);
		
		Actor* star = new Actor();
		star->AddComponent(new ShapeComponent(10, 5, sf::Color::Yellow));
		star->position->Translate(-10, -10);
		star->position->Scale(0.5, 0.5);
		moon->AddChild(star);

		Orange->AddActor(sun);
		Orange->AddActor(moon);
		Orange->AddActor(star);

		Orange->Run();
		delete(sun);
	}
	return 0;

}