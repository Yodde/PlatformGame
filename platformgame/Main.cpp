#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "game.h"
#include "objects.h"	

void loadFont(sf::Font &font, std::string path){
	if (!font.loadFromFile(path)){
		throw std::exception("File with font not found!", 100);
	}
}
bool exit();
//void gameMenuWriting(sf::Font font,sf::Text *menu){
//	const int size = 2;
//	sf::FloatRect frect[size];
//	std::string options[size] = { "New Game", "Exit" };
//	for (int i = 0; i < size; ++i){
//		menu[i].setFont(font);
//		menu[i].setCharacterSize(30);//default size
//		menu[i].setString(options[i]);
//		menu[i].setColor(sf::Color::White);
//		menu[i].setPosition(350 - menu[i].getLocalBounds().width / 2, 200 + i * 80);
//		frect[i] = menu[i].getLocalBounds();
//	}
//
//}

int main()
{
	int width = 800, height = 600;
	const int menuTabSize = 2;
	sf::Font font;
	auto fontPath = "mecha.ttf";
	sf::Vector2f center(width/2, height/2);
	sf::Vector2f size(width,height);
	auto gameWindow = new sf::RenderWindow(sf::VideoMode(width,height), "Menu");
	sf::Text menu[menuTabSize];
	int picked = 0;
	//to daæ w funkcji
	sf::FloatRect frect[menuTabSize];
	std::string options[menuTabSize] = { "New Game", "Exit" };
	for (int i = 0; i < menuTabSize; ++i){
		menu[i].setFont(font);
		menu[i].setCharacterSize(30);//default size
		menu[i].setString(options[i]);
		menu[i].setColor(sf::Color::Red);
		menu[i].setPosition(350 - menu[i].getLocalBounds().width / 2, 200 + i * 80);
		frect[i] = menu[i].getLocalBounds();
	}

	//---------------------------
	//main loop of the game
	try{
		loadFont(font, fontPath);
		// gameMenuWriting(font,menu);
	}
	catch (std::exception ex){
		std::cout << ex.what();
	}

	while (gameWindow->isOpen()){
		sf::View gameView(center, size);
		gameWindow->setView(gameView);
		sf::Event eventInGame;
		while (gameWindow->pollEvent(eventInGame)){
			if (eventInGame.type == sf::Event::Closed || (eventInGame.type == sf::Event::KeyPressed && eventInGame.type == sf::Keyboard::Escape)){
				gameWindow->close();
				break;
			}
			if (eventInGame.type == sf::Event::KeyPressed && eventInGame.key.code == sf::Keyboard::Up){
				--picked;
				if (picked < 0)
					picked = menuTabSize - 1;
			}
			else if (eventInGame.type == sf::Event::KeyPressed && eventInGame.key.code == sf::Keyboard::Down){
				++picked;
				if (picked > menuTabSize - 1)
					picked = 0;
			}
		}
		for (int i = 0; i < menuTabSize; ++i){
			if (i == picked){
				menu[i].setString(">>" + options[i] + "<<");
				menu[i].setColor(sf::Color::Green);
			}
			else{
				menu[i].setString(options[i]+" ");
				menu[i].setColor(sf::Color::Red);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
			switch (picked)
			{
			case 0:
				//new game
				break;
			case 1:
				gameWindow->close();
				break;
			default:
				break;
			}
		}

		gameWindow->clear();
		gameWindow->setMouseCursorVisible(false);
		for (int i = 0; i < menuTabSize; ++i)
			gameWindow->draw(menu[i]);
		gameWindow->display();
	}
//	std::cin.ignore(2);

	delete gameWindow;
	return 0;
}
// add confirmation prompt
bool exit(){
	return true;
}