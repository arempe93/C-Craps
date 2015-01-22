/*
	bank.cpp
	Andrew Rempe

	Implements the Bank class defined in bank.h
*/

#include "bank.h"

Bank::Bank(float initial_balance /* = 100 */) {

	balance = initial_balance;
	wager = 0.0;
}

bool Bank::bet(float amount) {

	// cannot bet more than you have
	if(amount > balance) return false;

	// otherwise, it's a valid bet
	wager = amount;
	return true;
}

float Bank::getBalance() {

	// subtract any current wagers from balance because they are on the table
	return balance - wager;
}

bool Bank::bankrupt() {

	// check if balance is 0. no need to subtract current wagers, this method will only be called after a round
	return balance == 0;
}

void Bank::win() {

	// player won bet, add wager to balance
	balance += wager;
	wager = 0.0;
}

void Bank::lose() {

	// player lost bet, subtract wager from balance
	balance -= wager;
	wager = 0.0;
}