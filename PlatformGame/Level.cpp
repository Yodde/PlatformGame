#include <string>
#include <fstream>
#include <vector>
#include <exception>
#include "Level.h"

Level::Level(std::string filename){
	readFromFile(filename);
}
Level::Level(){}
Level::~Level(){}

void Level::readFromFile(std::string filename){
	std::ifstream ifs;
	int textureT;
	ifs.open(filename);
	if (ifs.is_open()){
		ifs >> this->mapWidth >> this->mapHeigth;
		ifs >> this->tileWidth >> this->tileHeight;
		ifs >> this->playerPositionX >> playerPositionY;
		texture.resize(mapHeigth);
		for (int i = 0; i < mapHeigth; ++i)
			texture.at(i).resize(mapWidth);
		for (int i = 0; i < mapHeigth; ++i)
			for (int j = 0; j < mapWidth; ++j){
				ifs >> textureT;
				texture.at(i).at(j).textureType = Texture::textureType(textureT);
			}
	}
	ifs.close();
}
int Level::getMapHeigth(){
	return mapHeigth;
}
int Level::getMapWidth(){
	return mapWidth;
}
int Level::getTileHeigth(){
	return tileHeight;
}
int Level::getTileWidth(){
	return tileWidth;
}