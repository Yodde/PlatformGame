#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <exception>
#include "SFML\Graphics.hpp"
#include "texture.h"


class Level
{
public:
	Level();
	Level(std::string);
	~Level();
	void readFromFile(std::string);
	
	struct Tile{
		Texture::textureType textureType;
		//bool visible(),isWall(),itisatrap() etc 
	};
	//sf::Vector2i(int);
	std::vector<std::vector<Tile>> texture;
	int getMapHeigth();
	int getMapWidth();
	int getTileHeigth();
	int getTileWidth();

protected:
	int mapWidth, mapHeigth;
	int tileHeight, tileWidth;
	float playerPositionX, playerPositionY;
	//std::string fileName;
};

