/*
	Die.h
	Andrew Rempe

	Outlines the Die class
*/

#ifndef Die_H
#define Die_H

#include <string>

class Die {

	// stores values from rollDice()
	int first_die;
	int* first_die_p;

	int second_die;
	int* second_die_p;

public:

	// constructor and destructor
	Die();
	~Die();

	// assigns random values 1-6 to first_die and second_die
	void rollDice();

	// returns first_die + second_die
	int getTotalRoll();

	// prints the outcome of the roll to the screen
	void printRoll();
};

#endif