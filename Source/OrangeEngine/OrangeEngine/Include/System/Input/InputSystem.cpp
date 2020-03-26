#include "InputSystem.h"


InputSystem::InputSystem()
{
}
//
//InputSystem::~InputSystem()
//{
//}

void InputSystem::AddAction(int id, sf::Keyboard::Key key)
{
	m_Actions[id] = key;
}

bool InputSystem::IsActionTriggered(int id)
{
	return sf::Keyboard::isKeyPressed(m_Actions[id]);
}


sf::Vector2i InputSystem::GetMousePosition(sf::RenderWindow &window)
{
	return sf::Mouse::getPosition(window);
}