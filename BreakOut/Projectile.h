#pragma once
#include"DualVector.h"
#include<SFML/Graphics.hpp>
#include"Actors.h"
#include"Timer.h"
class Projectile:public Actors
{
	int cp = 6;
	float speed ;
	float initSpeed=4 ;
	Timer timerReset;
	sf::Vector2f dir = { 0,-1 };
	bool isPaused=true;
public:
	void setPos(sf::Vector2f pos);
	void bounceByPoint(int i);
	void setStatus(bool a);
	Projectile();
	void resetSpeed();
	void accelerate(float a);
	void bounce(char dir,float speed=0);
	bool dirUp()const;
	void tick(float delta);
	std::vector<sf::Vector2f> getControlPoints() const;
};

