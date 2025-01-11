#include "game.hpp"

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