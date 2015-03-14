#include "game.h"
Game::Game(sf::RenderWindow *&window)
{
}

Game::~Game()
{
	delete this-> window;
}