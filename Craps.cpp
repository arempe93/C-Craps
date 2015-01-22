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
enum GameState { WAGER, ROLLING, WIN, LOSE };

int main() {

	Die d;

	d.rollDice();
	d.printRoll();
}