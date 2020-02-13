#include "oInputManager.h"
#include "oTransform.h"
#include <SFML/Graphics.hpp>



oInputManager::oInputManager()
{
}


oInputManager::~oInputManager()
{
}

bool oInputManager::GetKeyDown(char key)
{
	if (keys[key])
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return true;
	else
		return false;
}

//bool oInputManager::onKeyPressed(char key)
//{
//	return keys[key] = true;
//}
bool oInputManager::onKeyPressed(char key)
{
	return keys[key] = true;
}

bool oInputManager::onKeyUnpressed(char key)
{
	return keys[key] = false;
}

void oInputManager::UpdateKey(float sec)
{
	//if (onKeyPressed('F'))
	//{
	//	exit(1);
	//}


	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	//{
	//	this->GetTransform()->Translate(10, 0);
	//}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	//{
	//	this->GetTransform()->Translate(-10, 0);
	//}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	//{
	//	this->GetTransform()->Translate(0, 10);
	//}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//a->GetTransform()->Translate(0, -10);
		//exit(7);
	}





	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		exit(0);
		//.onKeyPressed['D'];
		//Actor* ->GetTransform()->Translate(-10, 0);
	}

}






// bool keys[256];
// bool GetKeyDown(char key){
// if (keys[key])
//   return true;
// else 
//   return false; 
//}


// onKeyPressed(char key){
// keys[key] = true;
//}

// onKeyUnpressed....{
// keys[key] = false;
//}

//list of keys
//bool
//getKey bool
//
