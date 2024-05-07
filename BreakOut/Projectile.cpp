#include "Projectile.h"
#include"Configs.h"

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Texture texture;
	if (!texture.loadFromFile("Pics/ball.png"))
	{
		// Error...
	}

	sf::Sprite Sprite;
	Sprite.setTexture(texture);
	Sprite.setScale(sf::Vector2f(globalConfigs.getLen() / texture.getSize().x, globalConfigs.getLen() / texture.getSize().y));
	Sprite.setPosition(pos);
	target.draw(Sprite);

}
