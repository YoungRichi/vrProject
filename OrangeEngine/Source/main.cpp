#include <iostream>
#include "GameApp.h"

int main()
{
	GameApp myGame;
	myGame.CheckMemory();
	myGame.CPUSpeedRead();
	myGame.CheckStorage();
	std::cout << "Hello, World!" << std::endl;
	//create GameApp obj
	//run Init()
	myGame.bIsOnlyInstance();
	
	system("pause");
	return 0;
}