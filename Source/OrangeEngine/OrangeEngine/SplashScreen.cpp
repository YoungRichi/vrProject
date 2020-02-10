#pragma once

#include <SFML/Graphics.hpp>
#include "SplashScreen.h"


void SplashScreen::Splash()
{
	sf::Texture logo;

	if (!logo.loadFromFile("images/SplashScreen.png")) {
		exit(1);
	}

	sf::Sprite sp;
	sp.setTexture(logo);
	sp.scale(1, 1); // My logo is quite big in fact (1st google result btw)

	int logoWidth = sp.getGlobalBounds().width;
	int logoHeight = sp.getGlobalBounds().height;

	// With the logo loaded, I know its size, so i create the window accordingly
	sf::RenderWindow window(sf::VideoMode(logoWidth, logoHeight), "SFML", sf::Style::None); // <- Important!! Style=None removes title

	// To close splash window by timeout, I just suppose you want something like this, don't you?
	sf::Clock timer;
	sf::Time time = timer.restart();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			// event loop is always needed
		}
		// Window closed by time
		time += timer.restart();
		if (time >= sf::seconds(2.f)) {
			window.close();
		}

		window.clear();
		window.draw(sp);
		window.display();
	}

	// Then, reuse the window and do things again
	window.create(sf::VideoMode(600, 400), "SFML");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		//window.draw(sp);
		window.display();
	}

}

