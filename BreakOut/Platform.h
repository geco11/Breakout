#pragma once
#include"Configs.h"
#include<SFML/Graphics.hpp>
class Platform:public sf::Drawable
{
	sf::Vector2f pos;
	sf::Texture texture;
	float speed = 3;
	sf::Sprite Sprite;
	char RightButton = 0;
	char LeftButton = 0;
	sf::Vector2f size={2,0.5};
public:
	void syncScale();
	void syncPos();
	void buttonChange(sf::Keyboard::Key a,bool isPressed);
	Platform();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void move(sf::Vector2f shift);
	void tick(float delta);
};

