#include "Map.h"
#include<iostream>
#include <fstream>
#include"Block.h"

void Map::manual(std::vector<std::string> Map)
{
	map = Map;
}

void Map::LoadFromFile(std::string path)
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
	in.close(); 
}
bool Map::checkWall(sf::Vector2f point) {
	if(point.y<map.size()&&point.x<map[point.y].size())
	  return map[point.y][point.x] == '#';
	return false;
}
void Map::destroy(sf::Vector2f point) {
	map[point.y][point.x] = ' ';
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
