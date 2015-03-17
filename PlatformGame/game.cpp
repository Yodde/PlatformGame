#include "game.h"
Game::Game(sf::RenderWindow *&window){
}

Game::~Game(){
	delete this-> window;
}

void Game::start(){}
void Game::draw(){}
void Game::pause(){}
void Game::end(){}
bool Game::mapLoad(){
	return false;
}
void Game::update(){}
