#include "Platform.h"
#include<iostream>



void Platform::DeactivatePlatform()
{
	loadTexture("Pics/Platform.png");
}

void Platform::ActivatePLatform()
{
	loadTexture("Pics/PlatformSpeed.png");
}

void Platform::buttonChange(sf::Keyboard::Key a,bool isPressed)
{
	switch (a)
	{
	case sf::Keyboard::Left:
		if(isPressed)
		  LeftButton = -1;
		else
			LeftButton = 0;
		break;
	case sf::Keyboard::Right:
		if (isPressed)
			RightButton = 1;
		else
			RightButton = 0;
		break;
	}
}
void Platform::resetPos() {
	pos.x = globalConfigs.getGameScreenSize().x / 2.0;
	pos.y = globalConfigs.getGameScreenSize().y - (size.x / 2);
}

Platform::Platform()
{
	size = { 2,0.5 };

	loadTexture("Pics/platform.png");
	resetPos();
	syncPos();
	syncScale();
}


void Platform::move(sf::Vector2f shift)
{
	sf::Vector2f newPos = pos + shift;
	if (newPos.x > 0 && newPos.x + size.x < globalConfigs.getGameScreenSize().x)
		pos+=shift;
}

void Platform::tick(float delta)
{

	move({ (LeftButton + RightButton) * delta*speed,0 });
	syncPos();
}
