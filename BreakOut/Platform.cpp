#include "Platform.h"
#include<iostream>


Platform::Platform()
{
	pos.x = globalConfigs.getGameScreenSize().x / 2.0;
	pos.y= globalConfigs.getGameScreenSize().y - (size.x/2);
}

void Platform::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	sf::Texture texture;
	if (!texture.loadFromFile("Pics/platform.png"))
	{
		// Error...
	}
	// a=y/x
	sf::Sprite Sprite;
	sf::Vector2f sizePix;
	sizePix.x = globalConfigs.getLen() * size.x;
	sizePix.y = globalConfigs.getLen() * size.y;
	Sprite.setTexture(texture);
	Sprite.setScale(sf::Vector2f(sizePix.x/ texture.getSize().x, sizePix.y / texture.getSize().y));
    Sprite.setPosition(pos*globalConfigs.getLen());
	target.draw(Sprite);
	/*sf::RectangleShape plat(sf::Vector2f(50,13 ));
	plat.setFillColor(sf::Color::Blue);
	plat.setPosition(pos);
	target.draw(plat);*/
}

void Platform::move(sf::Vector2f shift)
{
	pos += shift;
}
