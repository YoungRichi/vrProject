
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
#include "../Scene1.h"


Scene1 *ss;
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE previousInstance, PSTR cmdLine, INT nCmdShow)
{

	ss->buildScene();
	return 0;

}