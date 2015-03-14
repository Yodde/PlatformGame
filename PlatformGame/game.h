#pragma once
#include <vector> 
#include <algorithm>

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game(sf::RenderWindow *&window);
	~Game();
	bool statr();
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
	
	//gamer 
	// vector objects;

	sf::View view;
	bool moveCamera;
};

