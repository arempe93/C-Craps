/*
	Craps.cpp
	Andrew Rempe

	Plays the game craps with the user
*/

// includes
#include "dice.h"
#include <iostream>
using namespace std;

// prototypes

// constants
enum GameState { WAGER, ROLLING, WIN, LOSE };

int main() {

	Dice d;

	d.roll();
	d.print();
}