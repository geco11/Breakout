#pragma once
#include<SFML/Graphics.hpp>
#include"Actors.h"
class Projectile:public Actors
{
	sf::Vector2f dir;
public:
	Projectile();
};

