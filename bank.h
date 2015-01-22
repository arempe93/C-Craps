/*
	bank.h
	Andrew Rempe

	Stores the user's bank balance and helps with wagers
*/

#ifndef bank_H
#define bank_H

class Bank {

	// stores current bank balance
	float balance;

	// stores current wager made by user
	float wager;

public:

	// constructor with optional initial balance
	Bank(float initial_balance = 100);

	// tries to make a bet and returns if possible
	bool bet(float amount);

	// returns user's current balance minus any active wager
	float getBalance();

	// returns whether balance is 0
	bool bankrupt();

	// wins the current round, adds wagered amount to balance
	void win();

	// loses the current round, subtracts wagered amount from balance
	void lose();
};

#endif