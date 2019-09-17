#include <iostream>
#include "GameApp.h"

int main()
{

	std::cout << "Hello, World!" << std::endl;

	//create GameApp obj
	//run Init()


	GameApp myGame; 
	myGame.bIsOnlyInstance();

	return 0;
}