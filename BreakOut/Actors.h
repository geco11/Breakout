#pragma once
#include<SFML/Graphics.hpp>
class Actors:public sf::Drawable
{
	sf::Texture texture;
	sf::Sprite Sprite;
protected:
	sf::Vector2f pos;	
	sf::Vector2f size;
public:
	void syncPos();
	void loadTexture(std::string a);
	void syncScale();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
};

