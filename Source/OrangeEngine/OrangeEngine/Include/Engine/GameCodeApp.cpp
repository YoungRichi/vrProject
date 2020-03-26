#include "GameCodeApp.h"
#include <direct.h>
#include <shlobj.h>
#include <stdio.h>


#if defined(_DEBUG)
#define GCC_NEW new(_NORMAL_BLOCK,__FILE__, __LINE__)
#endif



GameCodeApp::GameCodeApp()
{
	//TBD
}


GameCodeApp::~GameCodeApp()
{
	//TBD
}

//Checks instances
bool GameCodeApp::InitInstance(LPCTSTR InstanceCheck)
{
	CreateMutex(NULL, FALSE, InstanceCheck);

	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{

		cout << "Running multiple instances" << endl;
		return false;
	}

	cout << "Only one instance is running" << endl;
	return true;
}

//Checks storage
void GameCodeApp::CheckStorage(const DWORDLONG _diskSpaceNeeded)
{
	//Checking for storage space
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);

	unsigned __int64 const neededClusters = _diskSpaceNeeded / (diskfree.sectors_per_cluster * diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters)
	{
		// If here, nbot enough disk free space
		cout << "CheckStorage Failure: Not enough physical storage." << endl;

	}
	cout << "Space is available" << endl;

}

//Checks RAM
void GameCodeApp::CheckMemory(DWORDLONG physicalRAMNeeded, DWORDLONG virtualRAMNeeded)
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);

	// Multiplying RAM by bytes to get proper number
	physicalRAMNeeded *= byteMULTIPLIER;
	virtualRAMNeeded *= byteMULTIPLIER;

	if (status.ullAvailPhys < physicalRAMNeeded)
	{
		cout << "CheckMemory Failure: Not enough physical memory." << endl;
	}

	//Check for enough free memory
	if (status.ullAvailVirtual < virtualRAMNeeded)
	{
		// You don't have enough virtual memory available
		// Tell the player to shut down the copy of Visual Studio running in the background

		cout << "CheckMemory Failure: Not enough virtual memory" << endl;
	}

	char *buff = GCC_NEW char[virtualRAMNeeded];

	if (buff)
	{
		delete[] buff;
	}
	else {
		// even though there is enough memory, it isn't available in one block, which can be critical for games that manage their own memory
		cout << "CheckMemory Failure: Not enough contiguous memory." << endl;
	}
	cout << "Physical memory is available (MB): " << status.ullAvailPhys / byteMULTIPLIER << endl;
	cout << "Virtual memory is available (MB): " << status.ullAvailVirtual / byteMULTIPLIER << endl;
}

void GameCodeApp::CheckArchitecture()
{
	SYSTEM_INFO siSysInfo;

	// Copy the hardware information to the SYSTEM_INFO structure. 

	GetSystemInfo(&siSysInfo);
	GetNativeSystemInfo(&siSysInfo);

	// Display the contents of the SYSTEM_INFO structure. 
	switch (siSysInfo.wProcessorArchitecture)
	{

	case PROCESSOR_ARCHITECTURE_INTEL:
		_ArchString = "Processor Architecture: Intel x86\n";
		break;
	case PROCESSOR_ARCHITECTURE_IA64:
		_ArchString = "Processor Type: Intel x64\n";
		break;
	case PROCESSOR_ARCHITECTURE_AMD64:
		_ArchString = "Processor Type: x64\n";
		break;
	default:
		_ArchString = "Unknown processor architecture\n";
	}
	cout << _ArchString << endl;
}

//Checks CPU Speed
void GameCodeApp::ReadCPUSpeed()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;

	// open the key where the proc speed is hidden
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);
	//_TextString = to_string(lError);

	if (lError == ERROR_SUCCESS)
	{
		// query the key
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHz, &BufSize);
		//_TextString = to_string(RegQueryValueEx(hKey, L"~MHz", NULL, &type, (LPBYTE)&dwMHz, &BufSize));

		cout << to_string(dwMHz) << endl;
	}
}





