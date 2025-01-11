#include "end_screen.hpp"
#include <iostream>
using namespace std;

EndScreen::EndScreen(int s1,int s2, const vector<string>& winner_history) : score1(s1) , score2(s2), winners(winner_history) {}

void EndScreen::display_winners() {
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

void EndScreen::Draw() {
	clearScreen();
	printCentered("Game Over!");
	printCentered("Final Score - Player1: " + to_string(score1) + " Player2: " + to_string(score2));
	printCentered("Press 'Enter' to play again or 'Q' to quit.");
	cout << endl;
	display_winners(); 
}