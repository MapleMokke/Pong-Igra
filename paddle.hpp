#ifndef PADDLE_H
#define PADDLE_H

class Paddle {
private:
	const int x;
	int y;

public:
	Paddle(int startX, int startY);
	void moveUp();
	void moveDown();
	void set_y(int new_y);
	int get_x();
	int get_y();
};


#endif // !PADDLE_H
