#include "GameApp.h"
#include <windows.h>
#include <process.h>
#include "iostream"


GameApp::GameApp()
{
	
}


GameApp::~GameApp()
{
}

bool GameApp::bIsOnlyInstance()
{
	HANDLE hMutex = CreateMutex(NULL, FALSE, "Orange Engine");

	if (hMutex == NULL)
	{
		std::cout << ("error: %d\n", GetLastError());
		return false;
	}
	else if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		std::cout << ("Orange Engine opened existing window\n");
		return false;
	}
	else
	{
		std::cout << ("Orange Engine created new window\n");
		return true;
	}
}

void GameApp::InitInstance()
{
	//Create Mutex

}
