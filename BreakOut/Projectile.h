#pragma once
#include<SFML/Graphics.hpp>
class Projectile:public sf::Drawable
{
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite Sprite;
	sf::Vector2f dir;
public:
	Projectile();
	void syncScale();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

