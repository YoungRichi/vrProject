#include <SFML/Graphics.hpp>


void Show(sf::RenderWindow & renderWindow)
 {
  sf::Texture image;
  if (image.loadFromFile("images/SplashScreen.png") != true)
  {
   return;
  }

 sf::Sprite sprite(image);

  renderWindow.draw(sprite);
  renderWindow.display();

  sf::Event event;
   while (true)
   {
   while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed)
	  {
		 return;
	  }
	  else if (event.type == sf::Event::Closed)
	  {
		  renderWindow.close();
	  }
	  else
	  {
		  return;
	  }
	
	}
}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768, 32), "SFML works!");
	sf::CircleShape shape(500.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		
		Show(window);
		window.clear();
		window.draw(shape);
		window.display();

		
	}

	return 0;
}