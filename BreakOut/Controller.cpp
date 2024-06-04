#include "Controller.h"



void Controller::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(platform);
	target.draw(level);
	target.draw(proj);
	target.draw(screen);
}
bool Controller::ColisionPlatform()
{
	sf::Vector2f posPlat=platform.getPos();
	sf::Vector2f posProj = proj.getPos();
	if (posPlat.y <= posProj.y + proj.getSize().y) {
		if (posProj.x + proj.getSize().x / 2 >= posPlat.x && posProj.x + proj.getSize().x / 2 <= posPlat.x + platform.getSize().x) {
			return true;
		}
	}
	return false;
}
void Controller::buttonChange(sf::Keyboard::Key a, bool isPressed)
{
	platform.buttonChange(a, isPressed);
}
void Controller::tick(float delta) {
	this->delta = delta;
	if(ColisionPlatform())
		proj.bounce('y');
	platform.tick(delta);
	proj.tick(delta);
}
