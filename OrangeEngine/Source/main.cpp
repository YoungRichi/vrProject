#include <iostream>
#include "GameApp.h"

int main()
{
	GameApp myGame;
	myGame.bIsOnlyInstance();
	myGame.CheckMemory();
	myGame.CPUSpeedRead();
	myGame.SystemInfo();
	std::cout << "Hello, World!" << std::endl;
	//create GameApp obj
	//run Init()
	

	return 0;
}