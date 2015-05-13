#include "Player.h"
Player::Player(int positionX, int positionY, Level level){
	int tmp = 40;
	this->positionX = positionX;
	this->positionY = positionY;
	this->objectWidth = tmp;
	this->objectHeight = tmp + 20;
	this->speed = 4;
	//sf::RectangleShape tmpRect(sf::Vector2f(objectWidth, objectHeight));
	//this->objectRectangle = tmpRect;
	this->objectRectangle.setSize(sf::Vector2f(this->objectWidth, this->objectHeight));
	this->objectTexture.loadFromFile("klocek.png", sf::IntRect(0, 0, 40, 60));
	this->objectRectangle.setTexture(&objectTexture);
	this->objectRectangle.setPosition(positionX, positionY);
	this->vX = 0; this->vY = 0; this->mass = 0;
	this->objectStatus = Stay;

}
Player::~Player(){}
void Player::go(){}
void Player::goLeft(){
	this->objectStatus = Left;
}
void Player::goRight(){
	this->objectStatus = Rigth;
}
void Player::goDown(){
	this->objectStatus = Down;
}
void Player::goUp(){
	this->objectStatus = Up;
}
void Player::updateObject(){
	switch (objectStatus)
	{
	case Object::Stay:
		this->vX = 0;
		this->vY = 0;
		break;
	case Object::Left:
		this->vX = -this->speed;
	//	this->objectRectangle.move(this->vX, this->vY);
		break;
	case Object::Rigth:
		this->vX = this->speed;
	//	this->objectRectangle.move(this->vX, this->vY);
		break;
	case Object::Down:
		this->vY = this->speed;
		break;
	case Object::Up:
		this->vY= -this->speed;
		break;
	default:
		break;
	}
	if (vX != 0 || vY != 0)
		this->objectRectangle.move(this->vX, this->vY);
}
void Player::jump(){}
void Player::collision(){};
void Player::draw(sf::RenderWindow *&window){
	window->draw(this->objectRectangle);
}