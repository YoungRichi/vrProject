#pragma once
#include "../BaseComponent.h"

class RenderComponent : public BaseComponent
{
public:
	RenderComponent();
	~RenderComponent();

	void setSize(sf::Vector2f x);
	void setColor(sf::Color color);
	void setPosition(sf::Transformable p);
	void RenderObject(sf::RenderWindow &win, sf::Transform WorldTransform);
	void SetTexture(std::string path);
	void SetFont(std::string fontPath);
	void SetText(std::string text);
	void SetTextSize(int textSize);
	void SetTextColor(sf::Color textColor);
	void SetTextPosition(sf::Vector2f textPos);
	sf::FloatRect GetBounds();
	sf::RectangleShape getShape();


private:
	sf::RectangleShape defaultShape;
	sf::FloatRect shapeBounds;
	sf::Texture defaultTextrure;
	sf::Text defaultText;
	sf::Font defaultFont;

	ResourceHolder ResHolder;
};

