#include "game.hpp"
#include "paddle.hpp"
#include <iostream>
using namespace std;

Game::Game() 
	: player1(1, HEIGHT / 2 - PADDLE_SIZE / 2),
    player2(WIDTH - 2, HEIGHT / 2 - PADDLE_SIZE / 2),
    ball(WIDTH / 2, HEIGHT / 2),
    playing(true),
    score1(0),
    score2(0),
    consoleHandle(GetStdHandle(STD_OUTPUT_HANDLE)),
    lastBallMoveTime(std::chrono::steady_clock::now()) {}

void Game::gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(consoleHandle, pos);
}

void Game::clearLine(int y) {
    gotoxy(0, y);
    for (int i = 0; i < WIDTH; i++) cout << " ";
}

void Game::record_winner() {
    string winner;
    if (score1 == WIN_SCORE) {
        winner = "Player 1";
    }
    else {
        winner = "Player 2";
    }

    winners.push_back(winner);
}

void Game::Draw() {
	gotoxy(0, 0);
	cout << "First to " << WIN_SCORE << " wins!" << endl;
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

void Game::Input() {
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

void Game::Logic() {
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

bool Game::CheckRestart() {
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

void Game::ResetGame() {
	system("cls");
	score1 = 0;
	score2 = 0;
	ball.reset();
	player1.set_y(HEIGHT / 2 - PADDLE_SIZE / 2);
	player2.set_y(HEIGHT / 2 - PADDLE_SIZE / 2);
	playing = true;
	ball.random_direction();
}

void Game::Run() {
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