#pragma once
#include "../../Unity/Unity.h"

enum Input_ID
{
	Up,
	Down,
	Left,
	Right,
	Space
};

class InputSystem
{
public:
	InputSystem();

	static InputSystem* GetInstance()
	{
		static InputSystem instance;
		return &instance;
	}

	~InputSystem() {}

	void AddAction(int id, sf::Keyboard::Key key);
	bool IsActionTriggered(int id);

	sf::Vector2i GetMousePosition(sf::RenderWindow &window);

private:

	std::map<int, sf::Keyboard::Key> m_Actions;

	/*virtual string VOnKeyDown(char kcode) = 0;
	virtual void VOnKeyUp(char kcode) = 0;
	virtual string mouseEvents() = 0;*/
};
