#include <iostream>

using namespace std;


class ScoreBoard {
	static int score;
public:
	static void increaseScore(int _score) {
		score += _score;
	}
	static void printScore() {
		cout << "----------- SCORE BOARD -----------" << endl;
		cout << "Current Score: " << score << endl << endl;
	}
	static void resetScore() {
		score = 0;
	}

};

int ScoreBoard::score = 0;


int main() {
	ScoreBoard::increaseScore(10);
	ScoreBoard::increaseScore(5);
	ScoreBoard::increaseScore(8);
	ScoreBoard::printScore();
	ScoreBoard::resetScore();
	ScoreBoard::printScore();
	return 0;
}