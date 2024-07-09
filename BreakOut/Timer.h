#pragma once
#include<functional>
class Timer
{
	float duration;
	std::function <void()> onFinishFunction = nullptr;
	std::function <void()> onStartFunction=nullptr;
	bool isSet=false;
	float countdown;
public:
	void stop() { isSet = false; }
	void setOnStartFunction(std::function <void()> function) { onStartFunction = function; }
	void setOnFinishFunction(std::function <void()> function) { onFinishFunction = function; }
	void setDuration(float dur) { duration = dur; }
	bool isFinished() { return countdown <= 0; }
	void start() { 
		isSet = true;
		countdown = duration;
		if (onStartFunction)
			onStartFunction();
	}
	void tick(float delta) {
		if (!isSet)return;

		countdown -= delta;
		if (isFinished()) {
			isSet = false;
			if(onFinishFunction)
			  onFinishFunction();
		}
	}
};

