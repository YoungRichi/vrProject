#include "GameApp.h"
//#include "sysinfoapi.h"
//#include <windows.h>
#include <stdio.h>
#include <process.h>
#include <tchar.h>
#define DIV 1024
#define WIDTH 7
#include <iostream>
#include "intrin.h"
using namespace std;
GameApp::GameApp()
{
	//bIsOnlyInstance = true;
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
	return true;
}

void GameApp::CPUSpeedRead()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;

	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);
	if (lError == ERROR_SUCCESS)
	{
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)& dwMHz, &BufSize);
	}
	cout << "The CPU speed is: "<<dwMHz << " MHz;"<<endl;
	
	
}

void GameApp::SystemInfo()
{
	int CPUInfo[4] = { -1 };
	char CPUBrandString[0x40];
	__cpuid(CPUInfo, 0x80000000);
	unsigned int nExIds = CPUInfo[0];

	memset(CPUBrandString, 0, sizeof(CPUBrandString));

	// Get the information associated with each extended ID.
	for (int i = 0x80000000; i <= nExIds; ++i)
	{
		__cpuid(CPUInfo, i);
		// Interpret CPU brand string.
		if (i == 0x80000002)
			memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000003)
			memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000004)
			memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
	}

	cout << CPUBrandString << endl;
	system("pause");
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

