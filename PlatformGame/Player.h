#pragma once
#include "Objects.h"
class Player : public Object
{
public:
	Player(int positionX, int positonY, Level level);
	~Player();

	void go();
	void goLeft();
	void goRight();
	bool collision();
	void updateObject();
	void alive();
	void crouch();
	void jump();
	bool inAir();
	void draw(sf::RenderWindow *&);
	void goUp(); void goDown();
private:
};