#pragma once
#include "../Unity/Unity.h"
#include "../Engine/OrangeEngine.h"


using namespace std;

class GameCodeApp
{
public:
	GameCodeApp();
	~GameCodeApp();

	int byteMULTIPLIER = 1048576;

	//Checks for multiple instances
	bool InitInstance(LPCTSTR InstanceCheck);

	//Checks for storage space
	void CheckStorage(const DWORDLONG _diskSpaceNeeded);

	//Checks for memory
	void CheckMemory(DWORDLONG physicalRAMNeeded, DWORDLONG virtualRAMNeeded);

	//Checks CPU Speed
	void ReadCPUSpeed();

	//Checks Architecture
	void CheckArchitecture();

private:

	string _ArchString;
};

