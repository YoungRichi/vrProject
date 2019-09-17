#include "GameApp.h"
//#include "sysinfoapi.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#define DIV 1024
#define WIDTH 7
#include <iostream>
using namespace std;
GameApp::GameApp()
{
	bIsOnlyInstance = true;
}


GameApp::~GameApp()
{
}

void GameApp::InitInstance()
{


}

bool GameApp::CheckMemory()
{
	MEMORYSTATUSEX status; 
	GlobalMemoryStatusEx(&status);
	
	_tprintf(TEXT("There is  %*ld percent of memory in use.\n"),
		WIDTH, status.dwMemoryLoad);
	_tprintf(TEXT("There are %*I64d total KB of physical memory.\n"),
		WIDTH, status.ullTotalPhys / DIV);
	_tprintf(TEXT("There are %*I64d free  KB of physical memory.\n"),
		WIDTH, status.ullAvailPhys / DIV);
	_tprintf(TEXT("There are %*I64d total KB of paging file.\n"),
		WIDTH, status.ullTotalPageFile / DIV);
	_tprintf(TEXT("There are %*I64d free  KB of paging file.\n"),
		WIDTH, status.ullAvailPageFile / DIV);
	_tprintf(TEXT("There are %*I64d total KB of virtual memory.\n"),
		WIDTH, status.ullTotalVirtual / DIV);
	_tprintf(TEXT("There are %*I64d free  KB of virtual memory.\n"),
		WIDTH, status.ullAvailVirtual / DIV);

	// Show the amount of extended memory available.

	_tprintf(TEXT("There are %*I64d free  KB of extended memory.\n"),
		WIDTH, status.ullAvailExtendedVirtual / DIV);
	
	system("pause");
	return true;
}