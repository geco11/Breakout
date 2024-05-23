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

sf::Vector2f Actors::getScale()const
{
	sf::Vector2f Scale;
	if (!WithBorder) {
		sf::Vector2f sizePix;
		sizePix.x = globalConfigs.getLen() * size.x;
		sizePix.y = globalConfigs.getLen() * size.y;
		Scale=sf::Vector2f(sizePix.x / texture.getSize().x, sizePix.y / texture.getSize().y);
	}
	else {
		
		Scale.y = size.y * globalConfigs.getLen() / (texture.getSize().y - 2 * BorderThickness);
		Scale.x = size.x * globalConfigs.getLen() / (texture.getSize().x - 2 * BorderThickness);
	}
	return Scale;
}

void Actors::setThickness(float thickness)
{
	BorderThickness = thickness;
}

void Actors::setMode(bool m)
{
	WithBorder = m;
}

void Actors::syncPos()
{
	if(!WithBorder)
	  Sprite.setPosition(pos * globalConfigs.getLen());
	else {
		sf::Vector2f delta;
		delta.x = getScale().x * BorderThickness;
		delta.y = getScale().y * BorderThickness;
		Sprite.setPosition( pos* globalConfigs.getLen()- delta);
	}
}
void Actors::syncScale()
{
		//s = x / (L - 2t)
		Sprite.setScale(getScale());	
}

void Actors::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Sprite);
}
std::map<std::string, sf::Texture> Actors::library={};