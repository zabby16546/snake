
#ifndef SNAKE_H_
#define SNAKE_H_

#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using std::cout;
using std::vector;


struct position{int x,y;};

class Snake{
public:
	Snake(int x, int y); // constrcutor

	enum direction{ Up, Down, Left, Right }; // movement directions
	direction moveDirection; // the last change of direction.

	void addSegment(); // adds a segment to the snake
	void moveSnake(direction); // changes the direction of the snake
	void moveSimulate(sf::Clock &); // moves the snake without player input
	void displaySnake(sf::RenderWindow &window); // displays all segments
	bool inDisplay(int, int); // returns a true if snake is inside screen
	bool onBorder(int, int); // returns true if snake head is on border
private:
	vector<position> segments;
	bool moving;
};

// class Food{
// public:
// 	createFood(int x, int y);
// private:

// };

#endif

