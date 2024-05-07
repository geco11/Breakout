#pragma once
#include"Configs.h"
#include<SFML/Graphics.hpp>
class Block :public sf::Drawable
{
	sf::Vector2f pos;

public:
	Block(sf::Vector2f position);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
};

