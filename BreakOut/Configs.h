#pragma once
#include<SFML/Graphics.hpp>

class Configs {
	float len;
	sf::Vector2f gameScreenSize;
	sf::Vector2i screenSize;
public:
	void setScreen(sf::Vector2i screenSize);
	sf::Vector2f getGameScreenSize()const;
	void setGameScreen(sf::Vector2f g);
	float getLen()const;
	template <typename Type>
	sf::Vector2<Type> getScreen()const;
};
extern Configs globalConfigs;

template<typename Type>
inline sf::Vector2<Type> Configs::getScreen() const
{
	return sf::Vector2<Type>(screenSize.x,screenSize.y);
}
