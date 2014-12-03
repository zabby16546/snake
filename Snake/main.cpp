#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "snake.h"
#include <iostream>

using std::cout;

const int WINDOW_HEIGHT = 500;
const int WINDOW_WIDTH = 500;

int main(void){

	Snake Character(10,10);
	Character.addSegment();
	Character.addSegment();
	Character.addSegment();
	Character.addSegment();
	Character.addSegment();
	Character.addSegment();
	Character.addSegment();
	Character.addSegment();

	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"Snake!");
	sf::Clock gameTime;
	Snake::direction buttonDirection;

	while(gameWindow.isOpen()){

		sf::Event event;

		// React to events

		while(gameWindow.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				gameWindow.close();

			// Button press event
			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Left)
					buttonDirection = Snake::Left;
				if(event.key.code == sf::Keyboard::Right)						
					buttonDirection = Snake::Right;	
				if(event.key.code == sf::Keyboard::Up)	
					buttonDirection = Snake::Up;
				if(event.key.code == sf::Keyboard::Down)
					buttonDirection = Snake::Down;	
			}

		}



		// Simulate world
		if(buttonDirection != Character.moveDirection)
			Character.moveSnake(buttonDirection);

		Character.moveSimulate(gameTime);

		// Draw world
		gameWindow.clear(sf::Color(225,225,225));

		Character.displaySnake(gameWindow);
		gameWindow.display();

	}
}