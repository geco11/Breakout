#pragma once
#include<SFML/Graphics.hpp>
#include"Actors.h"
class Projectile:public Actors
{
	float speed = 2;
	sf::Vector2f dir = { 0.5,1 };
	bool isPaused=true;
public:
	void setStatus(bool a);
	Projectile();
	void bounce(char dir);
	bool dirUp()const;
	void tick(float delta);
};

