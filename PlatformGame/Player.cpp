#include "Player.h"
#include <iostream>
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
	this->objectStatus = Right;
}
void Player::goDown(){
	this->objectStatus = Down;
}
void Player::goUp(){
	this->objectStatus = Up;
}
void Player::updateObject(){
	// mo¿e tutaj sprawdzac kolizje?? 
	switch (objectStatus)
	{
	case Object::Stay:
		this->vX = 0;
		this->vY = 0;
		break;
	case Object::Left:
		if (collision()){
			objectStatus = Stay;
		}
		else
			this->vX = -this->speed;
	//	this->objectRectangle.move(this->vX, this->vY);
		break;
	case Object::Right:
		if (collision())
			objectStatus = Stay;
		else
			this->vX = this->speed;
	//	this->objectRectangle.move(this->vX, this->vY);
		break;
	case Object::Down:
		if (collision())
			objectStatus = Stay;
		else
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
bool Player::collision(){
	switch (objectStatus)
	{
	case Left:{
		int positionX = (getPositionXY().x - speed - 1) / Level::getTileWidth();
		for (int i = 0; i < objectHeight; ++i){
			int positionY = (getPositionXY().y + i) / Level::getTileHeigth();
			if (Level::texture.at(positionY).at(positionX).isWall){
				std::cout << "Kolizja na pozycji " << positionX << " " << positionY
					<< " " << getPositionXY().x << " " << getPositionXY().y << std::endl;
				return true;
			}
		}
		break;
	}
	case Right:{
		int positionX = (getPositionXY().x + speed + objectWidth) / Level::getTileWidth();
		for (int i = 0; i < objectHeight; ++i){
			int positionY = (getPositionXY().y + i) / Level::getTileHeigth();
			if (Level::texture.at(positionY).at(positionX).isWall){
				std::cout << "Kolizja na pozycji " << positionX << " " << positionY
					<< " " << getPositionXY().x << " " << getPositionXY().y << std::endl;
				return true;
			}
		}
		break;
	}
	case Down:{
		int positionY = (getPositionXY().y + objectHeight + speed) / Level::getTileHeigth();
		for (int i = 0; i < objectWidth; ++i){
			int positionX = (getPositionXY().x + i) / Level::getTileWidth();
			if (Level::texture.at(positionY).at(positionX).isWall){
				std::cout << "Kolizja na pozycji " << positionX << " " << positionY
					<< " " << getPositionXY().x << " " << getPositionXY().y << std::endl;
				return true;
			}
		}
		break;
	}
	default:
		return false;
	}
	return false;
}
void Player::draw(sf::RenderWindow *&window){
	window->draw(this->objectRectangle);
}