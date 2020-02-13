#pragma once

class Actor;
class oInputManager
{
public:
	oInputManager();
	~oInputManager();

	Actor* a;
	

	bool keys[256];

	bool GetKeyDown(char key);
	bool onKeyPressed(char key);
	bool onKeyUnpressed(char key);

	void UpdateKey(float sec);
};

