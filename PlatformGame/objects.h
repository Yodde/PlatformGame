#pragma once
#include<iostream>
#include<sfml/Graphics.hpp>

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
	virtual void updateStatus(); 
	void draw(sf::RenderWindow *&);
	void reset();
	void stop();
	virtual void collision();
	/* to specific class
	virtual void goLeft();
	virtual void goRight();
	virtual void jump();
	*/

	sf::Vector2i getPositionXY();
protected:
	enum status
	{
		stay,
		Left,
		Rigth,
		immoveable
	};
	int mass;
	//velocity on X and Y axis
	double vX, vY;
	//position of object
	int positionX, positionY;
	//in pixiels
	int speed;
	int objectWidth, objectHeight;
	sf::Texture objectTexture;
	sf::RectangleShape objectShape;
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

