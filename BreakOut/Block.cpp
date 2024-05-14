#include<iostream>
#include "Block.h"

Block::Block(sf::Vector2f position)
{
	size = { 1,1 };
	pos = position;
	loadTexture("Pics/block.png");
	syncPos();
	syncScale();
}
