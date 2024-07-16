#include "Controller.h"



void Controller::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(strToText("hp: " + std::to_string(hp), { 100,50 }));
	target.draw(strToText("Level: " + std::to_string(level.getIndex()+1), { 600,50 }));
	target.draw(platform);
	target.draw(level);
	target.draw(proj);
	target.draw(screen);
	if (globalConfigs.getIsFinished()) {
		sf::Text text = strToText("You Won", globalConfigs.getScreen<float>() / 2.f);
		text.setFillColor(sf::Color::Green);
		text.setCharacterSize(60);
		target.draw(text);
	}
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
sf::Text Controller::strToText(std::string content, sf::Vector2f pos)const {
	sf::Text text;
	text.setFillColor(sf::Color::Red);
	text.setFont(font);
	text.setString(content);
	text.setCharacterSize(40);
	text.setPosition(pos);
	return text;
}

Controller::Controller()
{
	Platform* platformPtr = &platform;
	timerSpace.setOnFinishFunction([platformPtr]() {platformPtr->DeactivatePlatform(); });
	timerSpace.setOnStartFunction([platformPtr]() {platformPtr->ActivatePLatform(); });
	timerSpace.setDuration(0.3);
    resetProj();
	if(!font.loadFromFile("Minecraft.ttf"))
		throw "error loading font";
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
	hp = 3;
	proj.setPos({ platform.getPos().x+platform.getSize().x / 2.0f - proj.getSize().x/2.0f,platform.getPos().y - proj.getSize().y});
}

void Controller::youLost() {
	if (hp == 0) {
		level.reload();
		resetProj();
	}
	else {
		if(hpTimer.isFinished())
		  hp--;
		hpTimer.setDuration(1);
		hpTimer.start();
	}
}

void Controller::youWon() {
	level.switchLevel(1);
	
    resetProj();
}

void Controller::tick(float delta) {
	this->delta = delta;
	
	if (ColisionPlatform() && !proj.dirUp()) {
		proj.bounce('y',platform.getSpeed());
		if (!timerSpace.isFinished())
			proj.accelerate(2);
	}
	if (globalConfigs.getGameScreenSize().y <= proj.getPos().y + proj.getSize().y + 0.1)
		youLost();
	if (level.getMap().isClear()) 
		youWon();
	hpTimer.tick(delta);
	controllBlocks();
	platform.tick(delta);
	timerSpace.tick(delta);
	proj.tick(delta);
}
