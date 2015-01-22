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

const char KEEP_ROLLING = 'r';
const char PLAY_AGAIN = 'p';
const char CHECK_BALANCE = 'b';
const char QUIT_GAME = 'q';

// -- prototypes

// prints out a welcome message with information on how to play
void welcome();

// loops through the game
void playGame();

// gets a valid bet from the user
void placeBet(Bank&, GameState&);

// parses outcomes of rolls
void outcome(int, int&, GameState&);

// does end of round operations and updates game state
void endRound(int&, Bank&, GameState&);

// prompts the user with a list of decisions based on game state
void decision(GameState&, Bank&, int);

// -- functions
int main() {

	welcome();
	playGame();
}

void welcome() {

	cout << endl;
	cout << "**************************************************" << endl;
	cout << "*                                                *" << endl;
	cout << "* ---------------- HOW TO PLAY ----------------- *" << endl;
	cout << "*                                                *" << endl;
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

	// first step in a new game is to place a bet
	GameState state = WAGER;

	// stores point to make if user rolls one
	int point = 0;

	// keep playing until the user quits
	while(state != QUIT) {

		// place a bet to start a round
		if(state == WAGER) placeBet(bank, state);

		// roll the dice and print the result
		dice.roll();
		dice.print();

		// parse outcome of last roll
		outcome(dice.getTotal(), point, state);

		// if a round is not in progress, or user quit - end the round
		if(state != ROLLING & state != QUIT) endRound(point, bank, state);

		// after dice roll, give user options based on outcome
		if(state != QUIT) decision(state, bank, point);
	}
}

void placeBet(Bank& bank, GameState& state) {

	bool bet_placed = false;
	float wager;

	// get a valid bet from the user
	do {

		cout << endl << "Your current balance is: $" << bank.getBalance() << endl;
		cout << "Place a wager: $";

		cin >> wager;
		bet_placed = bank.bet(wager);
	
	}while(!bet_placed);

	// after betting, the user rolls the dice
	state = ROLLING;
}

void outcome(int roll, int& point, GameState& state) {

	// check if the player is trying to make the point
	if(point != 0) {

		// player rolled a 7, round over
		if(roll == 7) state = LOSE;

		// player made the point
		if(roll == point) state = WIN;

	}else {

		// player rolled a 7 or 11 - auto win
		if(roll == 7 | roll == 11) state = WIN;

		// player rolled a 2, 3, or 12 - auto lose
		else if(roll == 2 | roll == 3 | roll == 12) state = LOSE;

		// if the player didn't auto lose or win, that roll becomes the point
		// state stays = to ROLLING
		else point = roll;
	}
}

void endRound(int& point, Bank& bank, GameState& state) {

	// clear the point value for next round
	point = 0;

	// if user won/lost, update bank balance
	if(state == WIN) {
	
		cout << "You win!" << endl;
		bank.win();
	
	}else if(state == LOSE) {
		
		cout << "You lose." << endl;
		bank.lose();
	}

	// if you're now out of money, its game over
	if(bank.bankrupt()) {
		cout << endl << "You're out of money! Better luck next time!" << endl << endl;
		state = QUIT;
	}
}

void decision(GameState& state, Bank& bank, int point) {

	// remind user of point to make if ROLLING
	if(state == ROLLING) cout << "Your point to make is " << point << "." << endl;

	// store user decision
	char choice;

	// give a list of decisions based on outcome
	if(state == ROLLING) {

		do {

			cout << "What do you want to do next? Keep rolling (R) or Quit (Q)?: ";
			cin >> choice;
		
		}while(choice != KEEP_ROLLING & choice != QUIT_GAME);
	
	}else {

		do {

			cout << "What do you want to do next? Play again (P), Check balance (B), or Quit (Q)?: ";
			cin >> choice;
		
			// checking balance should happen, then ask again what to do next
			if(choice == CHECK_BALANCE) cout << endl << "Your current balance is: $" << bank.getBalance() << endl << endl;

		}while(choice != PLAY_AGAIN & choice != QUIT_GAME);
	}

	// parse user decision, if choice was KEEP_ROLLING, no need to change state
	if(choice == PLAY_AGAIN) state = WAGER;
	else if(choice == QUIT_GAME) state = QUIT;
}