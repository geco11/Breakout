#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Configs.h"
class Map:public sf::Drawable
{
	int bricksC;
	std::vector<std::string>map;
public:
	int countWalls();
	bool isClear();
	void destroy(sf::Vector2f point);
	bool checkWall(sf::Vector2f point);
	void manual(std::vector<std::string>Map);
	bool LoadFromFile(std::string path);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

