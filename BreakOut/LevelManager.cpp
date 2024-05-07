#include "LevelManager.h"

LevelManager::LevelManager()
{
	map.LoadFromFile(getPath());
}

void LevelManager::switchLevel(int a)
{
	index += a;
	map.LoadFromFile(getPath());
}

std::string LevelManager::getPath()
{
	return  folder + "/map" + std::to_string(index)+".txt";
}

void LevelManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(map);
}
