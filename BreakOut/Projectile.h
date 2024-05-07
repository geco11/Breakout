#pragma once
#include<SFML/Graphics.hpp>
class Projectile:public sf::Drawable
{
	sf::Vector2f pos;
	sf::Vector2f dir;
public:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

