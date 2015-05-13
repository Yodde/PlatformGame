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
	void collision();
	void updateObject();
	void alive();
	void crouch();
	void jump();
	void draw(sf::RenderWindow *&);
	void goUp(); void goDown();
private:


};