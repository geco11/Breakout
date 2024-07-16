#include "Map.h"
#include<iostream>
#include <fstream>
#include"Block.h"

void Map::manual(std::vector<std::string> Map)
{
	map = Map;
}
bool Map::isClear() {
	return bricksC <= 0;
}	
int Map::countWalls(){
	bricksC = 0;
	for (int i = 0; i < map.size(); i++){
		for (int j = 0; j < map[i].size(); ++j) {
			if (map[i][j] = '#')
				bricksC++;
		}
	}
	return bricksC;
}

bool Map::LoadFromFile(std::string path)
{
	std::string line;

	std::ifstream in(path); 
	if (in.is_open())
	{
		map.clear();
		while (std::getline(in, line))
		{
			map.push_back(line);
		}
	}
	else
		return false;
	in.close(); 
	countWalls();
	return true;
}
bool Map::checkWall(sf::Vector2f point) {
	if(point.y<map.size()&&point.x<map[point.y].size())
	  return map[point.y][point.x] == '#';
	return false;
}
void Map::destroy(sf::Vector2f point) {
	map[point.y][point.x] = ' ';
	bricksC--;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0;i<map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == '#') {
				Block b(sf::Vector2f(j,i));
				target.draw(b);
			}
		}
	}
}
