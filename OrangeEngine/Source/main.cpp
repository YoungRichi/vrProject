
#include <iostream>
#include "GameApp.h"

int main()
{
	GameApp myGame;
	myGame.CheckMemory();
	myGame.CPUSpeedRead();
	std::cout << "Hello, World!" << std::endl;
	//create GameApp obj
	//run Init()
	myGame.bIsOnlyInstance();
	myGame.CheckStorage();

	return 0;
}