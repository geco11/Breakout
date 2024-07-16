#pragma once
#include<SFML/Graphics.hpp>

class Configs {
	float len;
	bool isFinished = false;
	sf::Vector2f gameScreenSize;
	sf::Vector2i screenSize;
public:
	void setIsFinished(bool a) { isFinished = a; }
	bool getIsFinished()const { return isFinished; }
	void setScreen(sf::Vector2i screenSize);
	/**
	screen size is abstract*/
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
