#include "Screen.h"
#include"Configs.h"
Screen::Screen()
{
	size=globalConfigs.getGameScreenSize();
	pos = {0,0};
	loadTexture("Pics/Screen.png");
	syncPos();
	syncScale();

}
