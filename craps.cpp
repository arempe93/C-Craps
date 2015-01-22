/*
	Craps.cpp
	Andrew Rempe

	Plays the game craps with the user
*/

// -- includes
#include "dice.h"
#include "bank.h"
#include <iostream>
using namespace std;

// -- constants
enum GameState { WAGER, ROLLING, WIN, LOSE, QUIT };

// -- prototypes

// prints out a welcome message with information on how to play
void welcome();

// loops through the game
void playGame();

// gets a valid bet from the user
void placeBet(Bank, GameState&);

int main() {

	welcome();
	playGame();
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

void playGame() {

	// create game objects
	Dice dice;
	Bank bank;
	GameState state = WAGER;

	while(state != QUIT) {

		// place a bet to start a round
		if(state == WAGER) placeBet(bank, state);

		if(state == ROLLING) cout << "ROLLING" << endl;

		state = QUIT;
	}
}

void placeBet(Bank bank, GameState& state) {

	bool bet_placed = false;
	float wager;

	do {

		cout << "Your current balance is: $" << bank.getBalance() << endl;
		cout << "Place a wager: $";

		cin >> wager;
		bet_placed = bank.bet(wager);
	
	}while(!bet_placed);
	
	state = ROLLING;
}