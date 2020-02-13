#pragma once
#ifndef __Draw_SYSTEM_H__
#define __Draw_SYSTEM_H__
#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>

using namespace std;

namespace sf {
	class RenderWindow;
}

class Actor;


// This system creates the window
class Draw
{
private:
	string szTitle;

public:
	Draw();
	~Draw();
	void WindowCreate();
	void WindowClose();
	bool IsWindowOpen();
	void RenderSplashScreen();
	void RenderActors(vector<Actor*>* actors);
	sf::RenderWindow* window;

};
#endif
