#pragma once
#include"Map.h"
#include<vector>
#include<SFML/Graphics.hpp>
class LevelManager :public sf::Drawable
{
	Map map;
	std::string folder="Maps";
	int index = 0;
public:
	int getIndex()const { return index; }
	void reload();
	Map& getMap() { return map; }
	LevelManager();
	void switchLevel(int a);
	std::string getPath();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

