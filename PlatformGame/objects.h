#pragma once
#include<SFML/Graphics.hpp>
#include "Level.h"
//__interface IObject
//{
//	~IObject(){}
//};

//base for player, enemies, bonuses ect.
class Object
{
public:
	virtual ~Object();
	virtual void go() = 0;
	virtual void goLeft();
	virtual void goRight();
	virtual void updateObject(); 
	virtual void goUp(); virtual void goDown();
	virtual void draw(sf::RenderWindow *&);
	void reset();
	void stop();
//	int getPositionX();
//	int getPositionY();
	virtual bool collision();
	virtual void jump();
	int getObjectWidth();
	int getObjectHeight();
	sf::Vector2f getPositionXY();


	/* to specific class
	virtual void goLeft();
	virtual void goRight();
	virtual void jump();
	*/

protected:
	enum status
	{
		Stay,
		Left,
		Right,
		Down,
		Up,
		Immoveable
	};
	status objectStatus;
	int mass;
	//velocity on X and Y axis
	double vX, vY;
	//position of object
	int positionX, positionY;
	
	//in pixiels
	int speed;
	int objectWidth, objectHeight;
	sf::Texture objectTexture;
	sf::RectangleShape objectRectangle;
};
//other classes
//maybe they'll be in other headers

class Bonus : Object
{
public:
	virtual ~Bonus();
	void addPoints();
	virtual void addLife();
	//take player//
protected:
	int value();

};

class Creature : Object
{
public:
	virtual ~Creature();
	void addPoints();

private:
	int value;
};