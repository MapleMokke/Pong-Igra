#include "paddle.hpp"

const int WIDTH = 40;
const int HEIGHT = 20;
const int PADDLE_SIZE = 4;
const int WIN_SCORE = 2;

Paddle::Paddle(int startX, int startY) : x(startX) , y(startY) {} 

void Paddle::moveUp() {
	if (y > 0) {
		y--;
	}
}

void Paddle::moveDown() {
	if (y < HEIGHT - PADDLE_SIZE) {
		y++;
	}
}

void Paddle::set_y(int new_y) {
	y = new_y;
}

int Paddle::get_x() {
	return x;
}

int Paddle::get_y() {
	return y;
}