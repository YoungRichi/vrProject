#pragma once
#ifndef __ORANGE_ENGINE_H__
#define __ORANGE_ENGINE_H__
#include <SFML/System/Time.hpp>
#include <windows.h>
#include <tchar.h>
#include <string>
#include "../Draw.h"
#include "OrangeEngine/OrangeEngine/SplashScreen.h"
#include <vector>
#include "OrangeEngine/OrangeEngine/Actor.h"
#include "OrangeEngine/OrangeEngine/oInputManager.h"

using namespace std;

class PhysicsEngine;


class OrangeEngine
{
private:
	bool IsOnlyInstance(LPCTSTR windowName);
	bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	void ReadCPUSpeed();
	void ErrorExit(const char* lpszFunction);
	//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM param, LPARAM lparam);
	/*
	 * For some unusual reason we always need 300 MB everywhere.
	 * Curious, isn't it?
	 */
	const DWORDLONG MB = 1024 * 1024;
	const DWORDLONG DISK_SPACE_NEEDED = 300 * MB;
	const DWORDLONG PHYSICAL_MEMORY_NEEDED = 300 * MB;
	const DWORDLONG VIRTUAL_MEMORY_NEEDED = 300 * MB;
	HINSTANCE hInstance;
	HINSTANCE previousInstance;
	PSTR cmdLine;
	INT nCmdShow;
	string szTitle;
	OrangeEngine();
	~OrangeEngine();
	static OrangeEngine* instance;
	vector<Actor*> actors;

	PhysicsEngine* physicsEngine;
	oInputManager* inputManager;

public:
	static OrangeEngine* GetInstance();
	bool InitInstance();
	void Run();
	void Print(string message);
	void PrintToWindow(string message);
	void AddActor(Actor* _actor);
	void update(sf::Time elapsedTime);

	PhysicsEngine* GetPhysics() { return physicsEngine; }
	void CreatePhysics();
	void DestroyPhysics();

	void CreateInputManager();

};
#endif // __ORANGE_ENGINE_H__


