
#include "Block.h"

Block::Block(sf::Vector2f position)
{
	pos = position;
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Texture texture;
	if (!texture.loadFromFile("Pics/block.png"))
	{
		// Error...
	}

	sf::Sprite Sprite;
	Sprite.setTexture(texture);
	Sprite.setScale(sf::Vector2f(globalConfigs.getLen()/ texture.getSize().x, globalConfigs.getLen()/ texture.getSize().y));
	Sprite.setPosition(pos);
	target.draw(Sprite);
	/*sf::RectangleShape box(sf::Vector2f(globalConfigs.getLen(), globalConfigs.getLen()));
	box.setFillColor(sf::Color(rand()%256, rand() % 256, rand() % 256));
	box.setPosition(pos);
	target.draw(box);*/
}

