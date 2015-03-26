#pragma once
#include <vector> 
#include <algorithm>
#include <iostream>
#include "Level.h"

class Game
{
public:
	Game(sf::RenderWindow *&window);
	~Game();
	bool startGame();
protected:
	enum gameStatus{
		Game_Start,
		Game_Pause,
		Game_Over
	};
	gameStatus game_status;
	void start();
	void pause();
	void end();
	bool mapLoad();
	void update();
	void draw();
private:
	sf::RenderWindow *window;
	Level level;
	//gamer 
	
	sf::Texture tabOfTextures[Texture::Object];
	std::vector<std::vector<sf::Sprite>> sprite;
	sf::View view;
	bool moveCamera;
};

