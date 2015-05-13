#pragma once
#include<SFML/Graphics.hpp>
#include "Objects.h"
#include "Level.h"
#include "Texture.h"
#include "Player.h"
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
	Player * player;
	bool gameOver;
	sf::Texture tabOfTextures[Texture::Object];
	std::vector<std::vector<sf::Sprite>> sprite;
	sf::View view;
	bool moveCamera;
};

