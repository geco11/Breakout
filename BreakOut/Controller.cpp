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
	if (a == sf::Keyboard::Space && isPressed) {
		
		timerSpace.start();
	}

	
}
Controller::Controller()
{
	Platform* platformPtr = &platform;
	timerSpace.setOnFinishFunction([platformPtr]() {platformPtr->DeactivatePlatform(); });
	timerSpace.setOnStartFunction([platformPtr]() {platformPtr->ActivatePLatform(); });
	timerSpace.setDuration(0.3);
    resetProj();
}
void Controller::controllBlocks() {
	std::vector<sf::Vector2f>controllPoints = proj.getControlPoints();
	for (int i = 0; i < controllPoints.size(); i++){
		if (level.getMap().checkWall(controllPoints[i])) {
			level.getMap().destroy(controllPoints[i]);
			proj.bounceByPoint(i);
		}
	}
}
void Controller::resetProj() {
	platform.resetPos();
	proj.resetSpeed();
	proj.setPos({ platform.getPos().x+platform.getSize().x / 2.0 - proj.getSize().x/2.0,platform.getPos().y - proj.getSize().y});
}

void Controller::youLost() {
	level.reload();
	resetProj();
}
void Controller::youWon() {
	level.switchLevel(1);
	
    resetProj();
}

void Controller::tick(float delta) {
	this->delta = delta;
	
	if (ColisionPlatform() && !proj.dirUp()) {
		proj.bounce('y');
		if (!timerSpace.isFinished())
			proj.accelerate(2);
	}
	if (globalConfigs.getGameScreenSize().y <= proj.getPos().y + proj.getSize().y + 0.1)
		youLost();
		if (level.getMap().isClear()) {
		  youWon();
		}
	controllBlocks();
	platform.tick(delta);
	timerSpace.tick(delta);
	proj.tick(delta);
}
