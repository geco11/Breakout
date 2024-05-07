#pragma once
#include"Platform.h"
#include"Configs.h"
#include"Projectile.h"
#include"LevelManager.h"
class Controller:public sf::Drawable
{
	Platform platform;
	Projectile proj;
	float delta;
	LevelManager level;
public:
	Controller() {}
	void tick(float delta);
	void movePlatform(sf::Vector2f a);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
};