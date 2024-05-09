#pragma once
#include"Configs.h"
#include<SFML/Graphics.hpp>
class Platform:public sf::Drawable
{
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite Sprite;
	sf::Vector2f size={2,0.5};
public:
	void syncScale();
	void syncPos();
	Platform();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void move(sf::Vector2f shift);
};

