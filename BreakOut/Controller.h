#pragma once
#include"Platform.h"
#include"Timer.h"
#include"Screen.h"
#include"Configs.h"
#include"Projectile.h"
#include"LevelManager.h"
class Controller:public sf::Drawable
{
	Platform platform;
	Projectile proj;
	Timer timerSpace;
	Screen screen;
	float delta;
	bool ColisionPlatform();
	LevelManager level;
public:
	void buttonChange(sf::Keyboard::Key a, bool isPressed);
	Controller();
	void tick(float delta);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
};