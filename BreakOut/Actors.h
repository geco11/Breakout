#pragma once
#include<SFML/Graphics.hpp>
class Actors:public sf::Drawable
{
	bool WithBorder=false;
	float BorderThickness=0;
	sf::Texture texture;
	static std::map<std::string, sf::Texture> library;
	sf::Sprite Sprite;
	sf::Vector2f getScale()const;
protected:
	sf::Vector2f pos;	
	sf::Vector2f size;
	void setThickness(float thickness);
	void setMode(bool m);
public:
	void syncPos();
	void loadTexture(std::string a);
	void syncScale();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
};

