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
	int hp = 3;
	Timer timerSpace;
	Screen screen;
	Timer hpTimer;
	sf::Font font;
	float delta;
	void youWon();
	sf::Text strToText(std::string text,sf::Vector2f pos)const;
	void resetProj();
	void youLost();
	bool ColisionPlatform();
	LevelManager level;
	void controllBlocks();
public:
	void buttonChange(sf::Keyboard::Key a, bool isPressed);
	Controller();
	void tick(float delta);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
};