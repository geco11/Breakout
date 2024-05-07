#include "Projectile.h"
#include"Configs.h"

Projectile::Projectile()
{
	if (!texture.loadFromFile("Pics/ball.png"))
	{
		// Error...
	}
	Sprite.setTexture(texture);
	Sprite.setPosition(pos);
	syncScale();
}
void Projectile::syncScale() {
	Sprite.setScale(sf::Vector2f(globalConfigs.getLen() / texture.getSize().x, globalConfigs.getLen() / texture.getSize().y));
}
void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
	target.draw(Sprite);

}
