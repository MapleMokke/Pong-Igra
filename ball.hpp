#ifndef BALL_H
#define BALL_H

enum Direction { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };

class Ball {
private:
	int x, y;
	Direction direction;

public:
	Ball(int startX, int startY);
	void move();
	void reset();
	void random_direction();
	void change_direction(Direction d);
	int get_x();
	int get_y();
	Direction get_direction();
};

#endif // !BALL_H
