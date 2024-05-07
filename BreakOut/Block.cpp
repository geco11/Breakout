#include<iostream>
#include "Block.h"

Block::Block(sf::Vector2f position)
{
	pos = position;
	if (!tex.loadFromFile("Pics/block.png")) {
		std::cerr << "error block load from file\n";
	}
	Sprite.setTexture(tex);
	Sprite.setPosition(pos);
	syncScale();
}
void Block::syncScale() {
	Sprite.setScale(sf::Vector2f(globalConfigs.getLen() / tex.getSize().x, globalConfigs.getLen() / tex.getSize().y));
}
void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	target.draw(Sprite);
	/*sf::RectangleShape box(sf::Vector2f(globalConfigs.getLen(), globalConfigs.getLen()));
	box.setFillColor(sf::Color(rand()%256, rand() % 256, rand() % 256));
	box.setPosition(pos);
	target.draw(box);*/
}

