#include "game.h"
#include <vector> 
#include <algorithm>
#include <iostream>

Game::Game(sf::RenderWindow *&window) :gameOver(false){
	view.setSize(480, 600);
	//view.setCenter(200.0, 100.0);
	this->window = window;
	this->window->setView(view);
	game_status = gameStatus::Game_Start;
	sf::RectangleShape rec(sf::Vector2f(32, 32));
	for (int i = 1; i < Texture::Object; ++i){
		tabOfTextures[i].loadFromFile("temp.png", sf::IntRect(0, 0, 32, 32));
		//exc
	}
	this->player = new Player(300, 100, level);

}

Game::~Game(){
	//delete this-> window;
	delete player;
}

bool Game::startGame(){
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
//	Player tmpP(2000, 100, level);
	

	//---- Rodzieliæ 
	while (game_status == gameStatus::Game_Start){
//		view.setCenter(this->player->getPositionXY());
		sf::Event event;
		while (this->window->pollEvent(event)){
			if ((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)){
				game_status = gameStatus::Game_Over;
				gameOver = true;
				break;
			}
			else if (event.type == sf::Event::KeyPressed){

				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					this->player->goRight();
					break;
				case sf::Keyboard::Left:
					this->player->goLeft();
					break;
				case sf::Keyboard::Up:
					this->player->goUp();
					break;
				case sf::Keyboard::Down:
					this->player->goDown();
					break;
				case sf::Keyboard::P:
					std::cout << this->player->getPositionXY().x << " " << this->player->getPositionXY().y << std::endl;
					break;
				default:
					break;
				}
			}
			else if (event.type == sf::Event::KeyReleased){
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
				case sf::Keyboard::Left:
				case sf::Keyboard::Up:
				case sf::Keyboard::Down:
					this->player->stop();
					break;
				default:
					break;
				}
			}
		}

		window->clear();
		this->update();
		this->draw();
		//player->draw(window);
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
	this->player->draw(this->window);
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
		for (int j = 0; j < mapWidth; ++j){
			sprite[i][j].setTexture(tabOfTextures[level.texture[i][j].textureType]);
			sprite[i][j].setPosition(j*level.getTileWidth(), i*level.getTileHeigth());
		}
	return true;
}
void Game::update(){
	this->view.setCenter(this->player->getPositionXY());
	this->window->setView(view);
	this->player->updateObject();


}
