#include "ball.hpp"
#include <iostream>
#include <cstdlib> //za rand()

const int WIDTH = 40;
const int HEIGHT = 20;
const int PADDLE_SIZE = 4;
const int WIN_SCORE = 5;

Ball::Ball(int startX, int startY) : x(startX), y(startY), direction(STOP) {}

void Ball::move() {
	switch (direction) {
	case STOP:
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UPLEFT:
		x--;
		y--;
		break;
	case DOWNLEFT:
		x--;
		y++;
		break;
	case UPRIGHT:
		x++;
		y--;
		break;
	case DOWNRIGHT:
		x++;
		y++;
		break;
	}
}
	
void Ball::reset() {
	x = WIDTH / 2;
	y = HEIGHT / 2;
	direction = STOP;
}

void Ball::random_direction() {
	direction = (Direction)((rand() % 6) + 1);
}

void Ball::change_direction(Direction d) {
	direction = d;
}

int Ball::get_x() {
	return x;
}

int Ball::get_y() {
	return y;
}

Direction Ball::get_direction() {
	return direction;
}
