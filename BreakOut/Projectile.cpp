#include "Projectile.h"
#include"Configs.h"


void Projectile::setStatus(bool a)
{
}
std::vector<sf::Vector2f> Projectile::getControlPoints() const{
	int cp = 6;
	std::vector<sf::Vector2f> res;
	DualVector dt;
	dt.setCartesian(pos.x, pos.y);
	dt.setPolar(size.x / 2, dt.getPhi() - 90);
	res.push_back(pos + size / 2.f + dt.tosf());
	float step = 180.f / (cp-1);
	for (int i = 1; i < cp; ++i) {
		dt.setPhi(dt.getPhi() + step);
		res.push_back(pos + size / 2.f + dt.tosf());
	}
	return res;
}

void Projectile::resetSpeed()
{
	speed = initSpeed;
}
Projectile::Projectile()
{
	
	speed=initSpeed;
	timerReset.setOnFinishFunction([this]() {this->resetSpeed(); });
	timerReset.setDuration(7);
	size = { 0.5,0.5 };
	loadTexture("Pics/ball.png");
	/*pos.x = globalConfigs.getGameScreenSize().x / 2.0;
	pos.y = globalConfigs.getGameScreenSize().y - (size.x / 2);*/
	syncPos();
	syncScale();
}
void Projectile::accelerate(float a)
{
	speed *= a;
	timerReset.start();
}
void Projectile::bounce(char dir)
{
	if (dir == 'y')
		this->dir.y *= -1;
	else
		if (dir == 'x')
			this->dir.x *= -1;
}
bool Projectile::dirUp() const
{
	if (dir.y < 0)return true;
	return false;
}
void Projectile::tick(float delta){
	timerReset.tick(delta);
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
