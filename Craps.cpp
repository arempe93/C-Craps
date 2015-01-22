/*
	Craps.cpp
	Andrew Rempe

	Plays the game craps with the user
*/

// includes
#include "Die.h"
#include <iostream>
using namespace std;

// prototypes

// constants
enum GameState { USER_WAGER, ROLLING, PLAYER_WINS, PLAYER_LOSES };

int main() {

	Die d;

	d.rollDice();
	d.printRoll();
}