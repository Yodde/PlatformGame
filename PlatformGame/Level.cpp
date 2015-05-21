#include <string>
#include <fstream>
#include <vector>
#include <exception>
#include "Level.h"

Level::Level(std::string filename){
	readFromFile(filename);
}
int Level::mapHeigth = 0;
int Level::mapWidth = 0;
int Level::tileHeight = 0;
int Level::tileWidth = 0;
std::vector<std::vector<Level::Tile>> Level::texture = std::vector<std::vector<Level::Tile>>();
Level::Level(){}
Level::~Level(){}

void Level::readFromFile(std::string filename){
	std::ifstream ifs;
	int textureType;
	ifs.open(filename);
	if (ifs.is_open()){
		ifs >> Level::mapWidth >> Level::mapHeigth;
		ifs >> Level::tileWidth >> Level::tileHeight;
		ifs >> this->playerPositionX >> playerPositionY;
		texture.resize(mapHeigth);
		for (int i = 0; i < mapHeigth; ++i)
			texture.at(i).resize(mapWidth);
		for (int i = 0; i < mapHeigth; ++i)
			for (int j = 0; j < mapWidth; ++j){
				ifs >> textureType;
				this->texture.at(i).at(j).textureType = Texture::textureType(textureType);
				if (textureType > 0)
					this->texture.at(i).at(j).isWall = true;
				else
					this->texture.at(i).at(j).isWall = false;
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