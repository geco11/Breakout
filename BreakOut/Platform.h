#pragma once
#include"Actors.h"
#include"Configs.h"
#include<SFML/Graphics.hpp>
class Platform:public Actors
{
	float speed = 3;
	char RightButton = 0;
	char LeftButton = 0;
public:
	void DeactivatePlatform();
	void ActivatePLatform();
	void resetPos();
	void buttonChange(sf::Keyboard::Key a,bool isPressed);
	Platform();
	void move(sf::Vector2f shift);
	void tick(float delta);
};

