#include "Projectile.h"
#include"Configs.h"


Projectile::Projectile()
{
	size = { 0.5,0.5 };
	loadTexture("Pics/ball.png");
	/*pos.x = globalConfigs.getGameScreenSize().x / 2.0;
	pos.y = globalConfigs.getGameScreenSize().y - (size.x / 2);*/
	syncPos();
	syncScale();
}
void Projectile::tick(float delta){
	float length = sqrt(dir.x * dir.x + dir.y * dir.y);
	sf::Vector2f newPos= (dir / length) * (speed * delta)+pos;
	if (newPos.y + size.y >= globalConfigs.getGameScreenSize().y || newPos.y <= 0)
		dir.y *= -1;
	if (newPos.x + size.x >= globalConfigs.getGameScreenSize().x || newPos.x <= 0)
		dir.x *= -1;
	sf::Vector2f step= (dir/ length) * (speed * delta);
	pos += step;
	syncPos();
}
