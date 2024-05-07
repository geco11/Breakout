#pragma once
#include"Configs.h"
#include<SFML/Graphics.hpp>
class Platform:public sf::Drawable
{
	sf::Vector2f pos;
	sf::Vector2f size={2,0.5};
public:
	Platform();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
	void move(sf::Vector2f shift);
};

