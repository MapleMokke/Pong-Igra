#ifndef  GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <conio.h> // Za getch() i kbhit()
#include <thread>  // Za std::this_thread::sleep_for
#include <chrono>  // Za std::chrono
#include <ctime>
#include <Windows.h>
#include <sstream> // Za to_string kod ispisa scora na kraju
#include <stdexcept>
#include "paddle.hpp"
#include "ball.hpp"
#include "start_screen.hpp"
#include "end_screen.hpp"
#include "thank_you_screen.hpp"
using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;
const int PADDLE_SIZE = 4;
const int WIN_SCORE = 5;

class Game {
private:
	Paddle player1; //lijevi igrac
	Paddle player2; //desni igrac
	Ball ball;
	bool playing;
	int score1;
	int score2;
	HANDLE consoleHandle;
	vector<string> winners;

	chrono::steady_clock::time_point lastBallMoveTime;
	const chrono::milliseconds ballMoveDelay = chrono::milliseconds(80);

public:
	Game();
	void gotoxy(int x, int y);
	void clearLine(int y);
	void record_winner();
	void Draw();
	void Input();
	void Logic();
	bool CheckRestart();
	void ResetGame();
	void Run();


};

#endif // ! GAME_H
