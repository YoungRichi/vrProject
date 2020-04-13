#include "RenderComponent.h"


RenderComponent::RenderComponent()
{


}


RenderComponent::~RenderComponent()
{

}

void RenderComponent::setSize(sf::Vector2f x)
{
	defaultShape.setSize(x);
	defaultShape.setOrigin(defaultShape.getPosition().x + defaultShape.getSize().x / 2.0f,
		defaultShape.getPosition().y + defaultShape.getSize().y / 2.0f);
}

void RenderComponent::setColor(sf::Color color)
{
	defaultShape.setFillColor(color);
}

void RenderComponent::setPosition(sf::Transformable p)
{
	defaultShape.setPosition(p.getPosition());
}

sf::RectangleShape  RenderComponent::getShape()
{
	return defaultShape;
}

void RenderComponent::RenderObject(sf::RenderWindow &win, sf::Transform WorldTransform)
{
	win.draw(getShape(), WorldTransform);
	win.draw(defaultText, WorldTransform);
}

void RenderComponent::SetTexture(std::string path)
{
	if (path == "")
	{
		return;
	}

	defaultTextrure.loadFromFile(path);
	if (!defaultTextrure.loadFromFile(path))
	{
		std::cout << "Texture not found!!" << std::endl;
		return;
	}
	defaultShape.setTexture(&defaultTextrure);

}

void RenderComponent::SetFont(std::string fontPath)
{
	if (fontPath == "")
	{
		return;
	}

	defaultFont.loadFromFile(fontPath);
	if (!defaultFont.loadFromFile(fontPath))
	{
		std::cout << "Font not found!" << std::endl;
		return;
	}
	defaultText.setFont(defaultFont);
}

void RenderComponent::SetText(std::string text)
{
	if (text == "")
	{
		return;
	}

	defaultFont.loadFromFile(ResHolder.ShadowBrush);

	if (!defaultFont.loadFromFile(ResHolder.ShadowBrush))
	{
		std::cout << "Font not found!" << std::endl;
		return;
	}
	defaultText.setFont(defaultFont);

	defaultText.setString(text);
}

void RenderComponent::SetTextSize(int textSize)
{
	defaultText.setCharacterSize(textSize);

	defaultText.setOrigin(defaultText.getPosition().x + defaultText.getCharacterSize() / 2.0f,
		defaultText.getPosition().y + defaultText.getCharacterSize() / 2.0f);
}

void RenderComponent::SetTextColor(sf::Color textColor)
{

	defaultText.setFillColor(textColor);
}

void RenderComponent::SetTextPosition(sf::Vector2f textPos)
{
	defaultText.setPosition(textPos);
}

sf::FloatRect RenderComponent::GetBounds()
{
	return defaultShape.getGlobalBounds();
}
