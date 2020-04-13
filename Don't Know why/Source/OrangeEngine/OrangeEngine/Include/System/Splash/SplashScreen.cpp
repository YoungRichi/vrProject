#pragma once
#include "../../Unity/Unity.h"
#include "SplashScreen.h"


void SplashScreen::Splash(sf::RenderWindow& _mainWindow, sf::Time& time)
{
	sf::Texture logo;

	if (!logo.loadFromFile("Assets/images/SplashScreen.png")) {
		exit(1);
	}

	sf::Sprite sp;
	sp.setTexture(logo);
	sp.scale(1, 1); // My logo is quite big in fact (1st google result btw)

	int logoWidth = sp.getGlobalBounds().width;
	int logoHeight = sp.getGlobalBounds().height;

	// With the logo loaded, I know its size, so i create the window accordingly
	_mainWindow.create(sf::VideoMode(logoWidth, logoHeight), "SFML", sf::Style::None); // <- Important!! Style=None removes title

	// To close splash window by timeout, I just suppose you want something like this, don't you?
	sf::Clock timer;
	

	while (_mainWindow.isOpen()) {
		sf::Event event;
		while (_mainWindow.pollEvent(event)) {
			// event loop is always needed
		}
		// Window closed by time
		time += timer.restart();
		if (time >= sf::seconds(2.f)) {
			_mainWindow.close();
		}

		_mainWindow.clear();
		_mainWindow.draw(sp);
		_mainWindow.display();
	}

	// Then, reuse the window and do things again
	_mainWindow.create(sf::VideoMode(1024, 720, 32), "OrangeEngine");

}

