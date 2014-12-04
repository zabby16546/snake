
#include "snake.h"

Snake::Snake(int x, int y){
	position segRow;
	segRow.x = x;
	segRow.y = y;
	segments.push_back(segRow);
	moving = false;
}

void Snake::addSegment(){
	position newSegment;
	
	switch(moveDirection){
	case Up:
		newSegment.x = segments[0].x;
		newSegment.y = segments[0].y+1*segments.size();
		break;
	case Down:
		newSegment.x = segments[0].x;
		newSegment.y = segments[0].y-1*segments.size();
		break;
	case Left:
		newSegment.x = segments[0].x+1*segments.size();
		newSegment.y = segments[0].y;
		break;
	case Right:
		newSegment.x = segments[0].x-1*segments.size();
		newSegment.y = segments[0].y;
	}
	
	segments.push_back(newSegment);
}

void Snake::moveSimulate(sf::Clock &timer){
	int lap = timer.getElapsedTime().asMilliseconds();

	if(moving == true && lap > 200){

		for(int k = segments.size(); k >= 1; --k){
			segments[k].x = segments[k-1].x;
			segments[k].y = segments[k-1].y;
			cout << segments[k].x << " " << segments[k].y;
		}		


		moveSnake(moveDirection);
		timer.restart();
	}
}

void Snake::moveSnake(direction direct){

	moving = true;

	moveDirection = direct;
	switch(moveDirection){
	case Up:
		segments[0].y--;
		break;
	case Down:
		segments[0].y++;
		break;
	case Left:
		segments[0].x--;
		break;
	case Right:
		segments[0].x++;
		break;
	}
}

void Snake::displaySnake(sf::RenderWindow &window){
	int snakesize = segments.size();

	sf::RectangleShape rectangle(sf::Vector2f(10,10));
	rectangle.setOrigin(0,0);
	rectangle.setFillColor(sf::Color(150,150,0));
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(sf::Color(0,0,0));

	for(int i = 0; i < snakesize; ++i){
		rectangle.setPosition(segments[i].x*10,segments[i].y*10);
		window.draw(rectangle);
	}
}

bool Snake::inDisplay(int width, int height){
	if(segments[0].x >= 0 && 
	   segments[0].y >= 0 && 
	   segments[0].x < width/5 && 
	   segments[0].y < height/5)
		return true;
	else
		return false;
}

bool Snake::onBorder(int w, int h){
	if(segments[0].x == 0 || 
	   segments[0].y == 0 ||
	   segments[0].x == w/5 ||
	   segments[0].y == h/5)
		return true;
	else
		return false;
}