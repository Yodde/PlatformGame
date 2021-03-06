#include<iostream>
#include "Objects.h"
void Object::draw(sf::RenderWindow *& window){
	window->draw(objectRectangle);
}
Object::~Object(){}
void Object::updateObject(){
	this->objectRectangle.move(vX, vY);
}
void Object::stop(){
	this->objectStatus = Stay;
}
sf::Vector2f Object::getPositionXY(){
	return objectRectangle.getPosition();
}
void Object::jump(){}
bool Object::collision(){
	return false;
}
void Object::goLeft(){}
void Object::goRight(){}
void Object::goUp(){}
void Object::goDown(){}
bool Object::inAir(){
	return false;
}