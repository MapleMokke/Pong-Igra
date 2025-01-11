#include "screen.hpp"
#include <iostream>
#include <string>
using namespace std;

Screen::Screen() : consoleHandle(GetStdHandle(STD_OUTPUT_HANDLE)) {}

void Screen::printCentered(const string& text) const {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);
	int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int padding = (consoleWidth - text.size()) / 2;

	// Ispis praznog prostora prije teksta da bi bio centriran
	for (size_t i = 0; i < padding; i++) cout << " ";
	cout << text << endl;
}