#include <iostream>
#include "OrangeEngine/OrangeEngine/SplashScreen.h"

//void Show(sf::RenderWindow & renderWindow)
// {
//  sf::Texture image;
//  if (image.loadFromFile("images/SplashScreen.png") != true)
//  {
//   return;
//  }
//
// sf::Sprite sprite(image);
//
//  renderWindow.draw(sprite);
//  renderWindow.display();
//
//  sf::Event event;
//   while (true)
//   {
//   while (renderWindow.pollEvent(event)){
//      if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed)
//	  {
//		 return;
//	  }
//	  else if (event.type == sf::Event::Closed)
//	  {
//		  renderWindow.close();
//	  }
//	  else
//	  {
//		  return;
//	  }
//	
//	}
//}
//}
SplashScreen* windows;
int main()
{
	windows->Splash();
	
	return 0;
}