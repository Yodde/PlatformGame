#pragma once
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
		bool isWall;
	};
	static std::vector<std::vector<Tile>> texture;
	static int getMapHeigth();
	static int getMapWidth();
	static int getTileHeigth();
	static int getTileWidth();

protected:

	static int mapWidth, mapHeigth;
	static int tileHeight, tileWidth;
	float playerPositionX, playerPositionY;
	//std::string fileName;
};

