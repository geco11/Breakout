#pragma once
#include<SFML/Graphics.hpp>
#include"Actors.h"
#include"Timer.h"
class Projectile:public Actors
{
	float speed ;
	float initSpeed=4 ;
	Timer timerReset;
	sf::Vector2f dir = { 0.5,1 };
	bool isPaused=true;
public:
	void setStatus(bool a);
	Projectile();
	void resetSpeed();
	void accelerate(float a);
	void bounce(char dir);
	bool dirUp()const;
	void tick(float delta);
};

