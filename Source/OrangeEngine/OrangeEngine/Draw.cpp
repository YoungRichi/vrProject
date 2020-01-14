#include <SFML/Graphics.hpp>
#include "Actor.h"
#include "ActorComponent.h"
#include "Draw.h"
#include "ShapeComponent.h"

Draw::Draw()
{
	window = new sf::RenderWindow(sf::VideoMode(1080, 960), "Orange Engine", sf::Style::None);
}

Draw::~Draw() {
	delete window;
}

void Draw::WindowCreate()
{
	window = new sf::RenderWindow(sf::VideoMode(1080, 960), "Orange Engine");
}

void Draw::WindowClose()
{
	if (window) window->close();
}

bool Draw::IsWindowOpen()
{
	if (window) return window->isOpen();
	return false;
}

void Draw::RenderSplashScreen()
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
}

void Draw::RenderActors(vector<Actor*>* actors) {
	window->clear();

	for (std::vector<Actor*>::iterator it = actors->begin(); it != actors->end(); ++it)
	{
		if ((*it)->GetComponent("shape"))
		{
			ShapeComponent* sc = (ShapeComponent*)(*it)->GetComponent("shape");
			sf::CircleShape shape(sc->GetRadius(),sc->GetEdge());
			shape.setFillColor(sc->GetColor());
			window->draw(shape, *(*it)->GetWorldTransform());
		}
	}

	window->display();
}
