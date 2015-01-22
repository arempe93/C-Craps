/*
	Craps.cpp
	Andrew Rempe

	Plays the game craps with the user
*/

// -- includes
#include "dice.h"
#include <iostream>
using namespace std;

// -- prototypes

// prints out a welcome message with information on how to play
void welcome();

// -- constants
enum GameState { WAGER, ROLLING, WIN, LOSE };

int main() {

	welcome();
}

void welcome() {

	cout << endl;
	cout << "**************************************************" << endl;
	cout << "* ---------------- HOW TO PLAY ----------------- *" << endl;
	cout << "* A player rolls two dice. If the sum is 7 or 11 *" << endl;
	cout << "* on the first roll, the player wins. If the sum *" << endl;
	cout << "* is 2,3, or 12 (called craps), the player loses *" << endl;
	cout << "* If the sum is 4, 5, 6, 8, 9 or 10, then that   *" << endl;
	cout << "* sum becomes the player's 'point.' To win you   *" << endl;
	cout << "* must continue to roll until you get your point *" << endl;
	cout << "* If you roll a 7 before you get your point, you *" << endl;
	cout << "* lose the round.                                *" << endl;
	cout << "**************************************************" << endl;
	cout << endl;
}