#pragma once
#include <windows.h>

class GameApp
{
public:
	GameApp();
	~GameApp();

	bool bIsOnlyInstance();
	void InitInstance();
	bool CheckMemory(); 
	void CPUSpeedRead();
	void CheckStorage();


protected:
	
	

};

