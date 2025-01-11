#include "start_screen.hpp"
#include <iostream>
using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;

void StartScreen::Draw() {
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