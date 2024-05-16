#include "Controller.h"



void Controller::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(platform);
	target.draw(level);
	target.draw(proj);
}
void Controller::buttonChange(sf::Keyboard::Key a, bool isPressed)
{
	platform.buttonChange(a, isPressed);
}
void Controller::tick(float delta) {
	this->delta = delta;
	platform.tick(delta);
	proj.tick(delta);
}
