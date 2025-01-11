#include "thank_you_screen.hpp"
#include <iostream>
using namespace std;

void ThankYouScreen::Draw() {
	clearScreen();
	printCentered("Thank you for playing!");
}