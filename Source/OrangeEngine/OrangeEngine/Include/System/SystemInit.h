#include "../Unity/Unity.h"
#include "../Engine/OrangeEngine.h"
#include "../Engine/GameCodeApp.h"
#include <direct.h>
#include <shlobj.h>
#include <stdio.h>

#pragma once

using namespace std;

class SystemInit
{
public:
	SystemInit();

	//GLOBAL OBJECT POINTER

	string _TextString2;
	string _InputString;
	bool isRunning = true;

	//LONG POINTERS
	LPCTSTR proj = "Novos_Enginex64Debug";

	//DWORDLONG variables
	const DWORDLONG checkSpace = 300;
	DWORDLONG checkPhysMem = 200;
	DWORDLONG checkVirtualMem = 200;
	DWORD CPUspeed;

	HINSTANCE hInst;

	bool Run();

	GameCodeApp* GCA;

};

