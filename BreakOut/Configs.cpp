#include "Configs.h"

sf::Vector2f Configs::getGameScreenSize()const{
	return gameScreenSize;
}
void Configs::setScreen(sf::Vector2i screenSize)
{
	this->screenSize = screenSize;
}
void Configs::setGameScreen(sf::Vector2f g) {
	gameScreenSize = g;
}

float Configs::getLen() const
{
	Configs* a = const_cast<Configs*>(this);
	float xLen=screenSize.x/gameScreenSize.x;
	float yLen =screenSize.y/gameScreenSize.y;
	if (xLen > yLen)
		a->len = yLen;
	else
		a->len = xLen;
	return len;
}


Configs globalConfigs;