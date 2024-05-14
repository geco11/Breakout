#include "Projectile.h"
#include"Configs.h"

Projectile::Projectile()
{
	size = { 0.5,0.5 };
	loadTexture("Pics/ball.png");
	syncPos();
	syncScale();
}
