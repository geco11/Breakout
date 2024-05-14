#include "Actors.h"
#include"Configs.h"
void Actors::loadTexture(std::string a)
{
	if (!texture.loadFromFile(a))
	{
		// Error...
	}
	Sprite.setTexture(texture);

}

void Actors::syncPos()
{
	Sprite.setPosition(pos * globalConfigs.getLen());
}
void Actors::syncScale()
{
	sf::Vector2f sizePix;
	sizePix.x = globalConfigs.getLen() * size.x;
	sizePix.y = globalConfigs.getLen() * size.y;
	Sprite.setScale(sf::Vector2f(sizePix.x / texture.getSize().x, sizePix.y / texture.getSize().y));
}

void Actors::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Sprite);
}
std::map<std::string, sf::Texture> Actors::library={};