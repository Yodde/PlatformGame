#include "game.h"
Game::Game(sf::RenderWindow *&window){
	view.setSize(600, 600);
	view.setCenter(2000.0, 500.0);

	this->window = window;
	game_status = gameStatus::Game_Start;
	sf::RectangleShape rec(sf::Vector2f(32, 32));
	for (int i = 1; i < Texture::Object; ++i){
		tabOfTextures[i].loadFromFile("temp.png", sf::IntRect(0, 0, 32, 32));
		//exc
	}

}

Game::~Game(){
	//delete this-> window;
}

bool Game::startGame(){
	bool gameOver = false;
	while (!gameOver){
		switch (game_status)
		{
		case Game_Start:
			this->start();
			break;
		default:
			break;
		}
	}
	return true;
}
void Game::start(){
	auto file("Mapa2.TXT");
	level.readFromFile(file);
	/* if */mapLoad();
	while (game_status == gameStatus::Game_Start){
		window->clear();
		draw();
		window->setFramerateLimit(60);
		window->display();
	}
}
void Game::draw(){
	this->window->clear();
	for (int i = 0; i < level.getMapHeigth(); ++i)
		for (int j = 0; j < level.getMapWidth(); ++j){
			this->window->draw(sprite.at(i).at(j));
		}
}
void Game::pause(){}
void Game::end(){}
bool Game::mapLoad(){
	auto mapWidth = level.getMapWidth();
	auto mapHeigth = level.getMapHeigth();

	sprite.resize(mapHeigth);
	for (int i = 0; i < mapHeigth; ++i)
		sprite[i].resize(level.getMapWidth());

	for (int i = 0; i < mapHeigth; ++i)
		for (int j = 0; j < mapHeigth; ++j){
			sprite[i][j].setTexture(tabOfTextures[level.texture[i][j].textureType]);
			sprite[i][j].setPosition(j*level.getTileWidth(), i*level.getTileHeigth());
			//sprite[i][j].setColor(sf::Color::Yellow);
		}
	return true;
}
void Game::update(){

}
