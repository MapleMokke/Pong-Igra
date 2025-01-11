#ifndef  END_SCREEN_H
#define END_SCREEN_H

#include "screen.hpp"
#include <vector>
#include <string>
using namespace std;

class EndScreen : public Screen {
private:
	int score1;
	int score2;
	vector<string> winners;

public:
	EndScreen(int s1, int s2, const vector<string>& winner_history);
	void display_winners();
	void Draw() override;
};

#endif // ! END_SCREEN_H
