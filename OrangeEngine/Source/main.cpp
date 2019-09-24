#include <iostream>
#include "GameApp.h"
#include "WinUser.h"

int main()
{
	GameApp myGame;
	if (!myGame.bIsOnlyInstance()) {
		MessageBox(NULL, "Multiple Instances Detected!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		//return 0;
		return 1;
	}
	myGame.CheckMemory();
	myGame.CPUSpeedRead();
	myGame.CheckStorage();
	myGame.SystemInfo();

	std::cout << "Hello, World!" << std::endl;
	//create GameApp obj
	//run Init()


	
	system("pause");
	return 0;
}