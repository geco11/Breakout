#include "LevelManager.h"

LevelManager::LevelManager()
{
	map.LoadFromFile(getPath());
}
void LevelManager::reload() {
	switchLevel(0);
}

void LevelManager::switchLevel(int a)
{
	index += a;

	if(!map.LoadFromFile(getPath())){
		globalConfigs.setIsFinished(true);
	}
}

std::string LevelManager::getPath()
{
	return  folder + "/map" + std::to_string(index)+".txt";
}

void LevelManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(map);
}
