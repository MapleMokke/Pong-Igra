#include <iostream>
#include <vector>
#include <string>
#include <conio.h> // Za getch() i kbhit()
#include <thread>  // Za std::this_thread::sleep_for
#include <chrono>  // Za std::chrono
#include <ctime>
#include <Windows.h>
#include <sstream> // Za to_string kod ispisa scora na kraju
#include <stdexcept> // Za iznimke
using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;
const int PADDLE_SIZE = 4;
const int WIN_SCORE = 5;

// Osnovna klasa za ekran
class Screen {
protected:
	HANDLE consoleHandle;

	void clearScreen() const {
		system("cls");
	}

	// Funkcija za centriranje teksta na ekranu
	void printCentered(const string& text) const {
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(consoleHandle, &csbi);
		int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		int padding = (consoleWidth - text.size()) / 2;

		// Ispis praznog prostora prije teksta da bi bio centriran
		for (size_t i = 0; i < padding; i++) cout << " ";
		cout << text << endl;
	}

public:
	Screen() : consoleHandle(GetStdHandle(STD_OUTPUT_HANDLE)) {}
	virtual void Draw() = 0; // Cista virtualna funkcija za ispis
};

// Klasa za pocetni ekran koja nasljedjuje Screen
class StartScreen : public Screen {
public:
	void Draw() override {
		clearScreen();
		for (int i = 0; i < HEIGHT / 2 - 3; i++) cout << endl;

		// Centriranje ispisa
		printCentered("-------------------------");
		printCentered("          PONG           ");
		printCentered("-------------------------");
		cout << endl;

		printCentered("Press 'Enter' to start");
		printCentered("Press 'Q' to quit");
	}
};

// Klasa za ekran prije gasenja igre koja nasljedjuje Screen
class ThankYouScreen : public Screen {
public:
	void Draw() override {
		clearScreen();
		printCentered("Thank you for playing!");
	}
};

// Klasa za zavrsni ekran koja nasljedjuje Screen
class EndScreen : public Screen {
private:
	int score1, score2;
	vector<string> winners;
public:
	EndScreen(int s1, int s2, const vector<string>& winner_history) : score1(s1), score2(s2), winners(winner_history) {}

	void display_winners() {
		printCentered("--- Winner history ---");
		if (winners.empty()) {
			printCentered("No games have been played.");
		}
		else {
			for (int i = 0; i < winners.size(); i++) {
				printCentered("Game " + to_string(i + 1) + ": " + winners[i]);
			}
		}
		printCentered("----------------------");
	}

	void Draw() override {
		clearScreen();
		printCentered("Game Over!");
		printCentered("Final Score - Player1: " + to_string(score1) + " Player2: " + to_string(score2));
		printCentered("Press 'Enter' to play again or 'Q' to quit.");
		cout << endl;
		display_winners();
	}
};


class Paddle {
private:
	const int x;
	int y;
public:
	Paddle(int startX, int startY) : x(startX), y(startY) {}

	void moveUp() {
		if (y > 0) {
			y--;
		}
	}

	void moveDown() {
		if (y < HEIGHT - PADDLE_SIZE) {
			y++;

		}
	}

	void set_y(int new_y) {
		y = new_y;
	}

	int get_x() {
		return x;
	}

	int get_y() {
		return y;
	}
};


enum Direction { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6 };


class Ball {
private:
	int x, y;
	Direction direction;

public:
	//int x, y;
	//int dirX, dirY;

	Ball(int startX, int startY) : x(startX), y(startY), direction(STOP) {}

	void move() {
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

	void reset() {
		x = WIDTH / 2;
		y = HEIGHT / 2;
		direction = STOP;
	}

	void random_direction() {
		direction = (Direction)((rand() % 6) + 1);
	}

	void change_direction(Direction d) {
		direction = d;
	}

	int get_x() {
		return x;
	}

	int get_y() {
		return y;
	}

	Direction get_direction() {
		return direction;
	}
};



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

	void gotoxy(int x, int y) {
		COORD pos = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition(consoleHandle, pos);
	}

	void clearLine(int y) {
		gotoxy(0, y);
		for (int i = 0; i < WIDTH; i++) cout << " ";
	}

	// Brzina lopte
	chrono::steady_clock::time_point lastBallMoveTime;
	const chrono::milliseconds ballMoveDelay = chrono::milliseconds(80);


public:
	Game() : player1(1, HEIGHT / 2 - PADDLE_SIZE / 2),
		player2(WIDTH - 2, HEIGHT / 2 - PADDLE_SIZE / 2),
		ball(WIDTH / 2, HEIGHT / 2),
		playing(true),
		score1(0),
		score2(0),
		consoleHandle(GetStdHandle(STD_OUTPUT_HANDLE)),
		lastBallMoveTime(chrono::steady_clock::now()) {}


	void record_winner(){
		string winner;
		if (score1 == WIN_SCORE) {
			winner = "Player 1";
		}
		else {
			winner = "Player 2";
		}

		winners.push_back(winner);
	}

	void Draw() {
		gotoxy(0, 0);
		cout << "First to "<< WIN_SCORE <<" wins!" << endl;
		gotoxy(0, 1);
		//gornji zid
		for (int i = 0; i < WIDTH; i++) {
			cout << '-';
		}
		cout << endl;

		//podrucje igre
		for (int y = 0; y < HEIGHT; y++) {
			gotoxy(0, y + 2);
			for (int x = 0; x < WIDTH; x++) {
				if (x == 0 || x == WIDTH - 1) {
					cout << " "; // Zidovi
				}
				else if (x == player1.get_x() && y >= player1.get_y() && y < player1.get_y() + PADDLE_SIZE) {
					cout << "\xDB"; // Lijevi reket
				}
				else if (x == player2.get_x() && y >= player2.get_y() && y < player2.get_y() + PADDLE_SIZE) {
					cout << "\xDB"; // Desni reket
				}
				else if (x == ball.get_x() && y == ball.get_y()) {
					cout << "o"; // Lopta
				}
				else if (x == WIDTH / 2) {
					cout << "|"; // Središnja linija
				}
				else {
					cout << " "; // Prazan prostor
				}
			}
		}

		//donji zid
		gotoxy(0, HEIGHT + 2);
		for (int i = 0; i < WIDTH; i++)
			cout << "-";
		gotoxy(0, HEIGHT + 3);

		// Rezultat
		cout << "Left Score: " << score1 << "                        Right Score: " << score2 << endl;
		gotoxy(0, HEIGHT + 4);
		cout << "Press 'Q' to end game." << endl;
	}

	void Input() {
		if (_kbhit()) {
			char key = _getch();
			try {
				if (key == 'w' || key == 'W') //kontrole lijevog igraca (W i S)
					player1.moveUp();
				else if (key == 's' || key == 'S')
					player1.moveDown();
				else if (key == 'i' || key == 'I') //kontrole desnog igraca (I i K)
					player2.moveUp();
				else if (key == 'k' || key == 'K')
					player2.moveDown();
				else if (key == 'q' || key == 'Q')
					playing = false;
				else {
					// Bacanje standardne iznimke s prilagoðenom porukom
					throw runtime_error("\nInvalid input! Use 'W' and 'S' for Left player, 'I' and 'K' for Right player.");
				}
			}
			catch (const runtime_error& e) {
				cout << e.what() << endl;
			}

		}
	}

	void Logic() {
		auto currentTime = chrono::steady_clock::now();
		auto elapsedTime = chrono::duration_cast<chrono::milliseconds>(currentTime - lastBallMoveTime);

		if (elapsedTime >= ballMoveDelay) {
			ball.move();

			lastBallMoveTime = currentTime;
		}

		//zid
		if (ball.get_y() == 0) {
			if (ball.get_direction() == UPRIGHT)
				ball.change_direction(DOWNRIGHT);
			else if (ball.get_direction() == UPLEFT)
				ball.change_direction(DOWNLEFT);
		}

		//zid
		if (ball.get_y() == HEIGHT - 1) {
			if (ball.get_direction() == DOWNRIGHT)
				ball.change_direction(UPRIGHT);
			else if (ball.get_direction() == DOWNLEFT)
				ball.change_direction(UPLEFT);
		}

		//lijevi reket
		if (ball.get_x() == player1.get_x() + 1 &&
			ball.get_y() >= player1.get_y() &&
			ball.get_y() < player1.get_y() + PADDLE_SIZE)
			ball.change_direction(static_cast<Direction>((rand() % 3) + 4));

		//desnim reket
		if (ball.get_x() == player2.get_x() - 1 &&
			ball.get_y() >= player2.get_y() &&
			ball.get_y() < player2.get_y() + PADDLE_SIZE)
			ball.change_direction(static_cast<Direction>((rand() % 3) + 1));


		// bodovi za desnog igraèa
		if (ball.get_x() == 0) {
			score2++;
			ball.reset();
			ball.random_direction();
		}

		// bodivi za lijevog igraèa
		if (ball.get_x() == WIDTH) {
			score1++;
			ball.reset();
			ball.random_direction();
		}

		// Provjera pobjednika
		if (score1 == WIN_SCORE || score2 == WIN_SCORE) {
			record_winner();
			playing = false;
		}

	}

	bool CheckRestart() {
		char choice;
		bool errorDisplayed = false;
		while (true) {
			choice = _getch();
			if (choice == '\r') { // tipka Enter
				ResetGame();
				return true;
			}
			else if (choice == 'q' || choice == 'Q') {
				return false;
			}

			else {
				if (!errorDisplayed) {
					try {
						throw std::runtime_error("\nInvalid input! Press 'Enter' to start or 'Q' to quit.");
					}
					catch (const std::runtime_error& e) {
						cout << e.what() << endl;
						errorDisplayed = true;  // Mark that the error has been displayed
					}
				}
			}
		}
	}

	void ResetGame() {
		system("cls");
		score1 = 0;
		score2 = 0;
		ball.reset();
		player1.set_y(HEIGHT / 2 - PADDLE_SIZE / 2);
		player2.set_y(HEIGHT / 2 - PADDLE_SIZE / 2);
		playing = true;
		ball.random_direction();
	}

	void Run() {
		StartScreen start;
		ThankYouScreen tnx;

		while (true) {
			system("cls");
			start.Draw();
			char choice = _getch();

			if (choice == 'Q' || choice == 'q') {
				tnx.Draw();
				this_thread::sleep_for(chrono::seconds(2));
				HWND hwnd = GetConsoleWindow();
				PostMessage(hwnd, WM_CLOSE, 0, 0);
				return;
			}
			else if (choice == '\r') {
				ball.random_direction();
				while (true) {
					system("cls");
					while (playing) {
						Draw();
						Input();
						Logic();
					}

					EndScreen end(score1, score2, winners);
					end.Draw();

					if (!CheckRestart()) {
						tnx.Draw();
						this_thread::sleep_for(chrono::seconds(2));
						HWND hwnd = GetConsoleWindow();
						PostMessage(hwnd, WM_CLOSE, 0, 0);
						break;
					}
				}
			}
			else {
				try {
					throw std::runtime_error("\nInvalid input! Press 'Enter' to start or 'Q' to quit.");
				}
				catch (const std::runtime_error& e) {
					cout << e.what() << endl;
					this_thread::sleep_for(chrono::seconds(1));
				}
			}
		}
	}
};

void hideCursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE; //sakrij kursor;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int main() {
	hideCursor();
	srand(static_cast<unsigned>(time(0)));
	Game pong;
	pong.Run();
	return 0;
}
