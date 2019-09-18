#include "GameApp.h"
//#include "sysinfoapi.h"
//#include <windows.h>
#include <stdio.h>
#include <process.h>
#include <tchar.h>
#define DIV 1024
#define WIDTH 7
#include <iostream>
#include <direct.h>
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

TCHAR   g_szBorder[] = _T("======================================================================\n");
TCHAR   g_szTitle1[] = _T("|DRIVE|TOTAL CLUSTERS|AVAIL CLUSTERS|SECTORS / CLUSTER|BYTES / SECTOR|\n");
TCHAR   g_szTitle2[] = _T("|=====|==============|==============|=================|==============|\n");
TCHAR   g_szLine[] = _T("|  A: |              |              |                 |              |\n");

void utoiRightJustified(TCHAR* szLeft, TCHAR* szRight, unsigned uVal);

void GameApp::CheckStorage()
{
	TCHAR szMsg[4200];
	struct _diskfree_t df = { 0 };
	ULONG uDriveMask = _getdrives();
	unsigned uErr, uLen, uDrive;

	printf(g_szBorder);
	printf(g_szTitle1);
	printf(g_szTitle2);

	for (uDrive = 1; uDrive <= 26; ++uDrive) {
		if (uDriveMask & 1) {
			uErr = _getdiskfree(uDrive, &df);
			memcpy(szMsg, g_szLine, sizeof(g_szLine));
			szMsg[3] = uDrive + 'A' - 1;

			if (uErr == 0) {
				utoiRightJustified(szMsg + 8, szMsg + 19, df.total_clusters);
				utoiRightJustified(szMsg + 23, szMsg + 34, df.avail_clusters);
				utoiRightJustified(szMsg + 38, szMsg + 52, df.sectors_per_cluster);
				utoiRightJustified(szMsg + 56, szMsg + 67, df.bytes_per_sector);
			}
			else {
				uLen = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL,
					uErr, 0, szMsg + 8, 4100, NULL);
				szMsg[uLen + 6] = ' ';
				szMsg[uLen + 7] = ' ';
				szMsg[uLen + 8] = ' ';
			}

			printf(szMsg);
		}

		uDriveMask >>= 1;

	}

	printf(g_szBorder);

	int bytes_per_megabyte = 1048576;
	int neededBytes = 300 * bytes_per_megabyte;
	int neededClusters = neededBytes / (df.bytes_per_sector * df.sectors_per_cluster);
	int avail_bytes = df.avail_clusters * df.bytes_per_sector * df.sectors_per_cluster;


	//76800 clusters needed
	if (df.avail_clusters >= neededClusters) {
		std::cout << "You need " << neededClusters << " clusters" << std::endl;
		std::cout << "You have enough disk storage memory" << std::endl;
	}
	else
		std::cout << "Not enough disk storage memory" << std::endl;
}

void utoiRightJustified(TCHAR* szLeft, TCHAR* szRight, unsigned uVal) {
	TCHAR* szCur = szRight;
	int nComma = 0;

	if (uVal) {
		while (uVal && (szCur >= szLeft)) {
			if (nComma == 3) {
				*szCur = ',';
				nComma = 0;
			}
			else {
				*szCur = (uVal % 10) | 0x30;
				uVal /= 10;
				++nComma;
			}

			--szCur;
		}
	}
	else {
		*szCur = '0';
		--szCur;
	}

	if (uVal) {
		szCur = szLeft;

		while (szCur <= szRight) {
			*szCur = '*';
			++szCur;
		}
	}
}

