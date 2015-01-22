/*
	Die.cpp
	Andrew Rempe

	Implements the Die class defined in Die.h
*/

#include "Die.h"
#include <iostream>
#include <stdlib.h>

Die::Die() {

	// give the dice some initial values
	first_die = 0;
	first_die_p = &first_die;
	
	second_die = 0;
	second_die_p = &second_die;

	// seed the random number generator
	srand(time(NULL));
}

void Die::rollDice() {

	// choose a random number from 1-6 and assign to dice
	first_die = (rand() % 6) + 1;
	second_die = (rand() % 6) + 1;
}

int Die::getTotalRoll() {

	// returns total value
	return first_die + second_die;
}

void Die::printRoll() {

	// print individual and total roll
	std::cout << first_die << " + " << second_die << " = " << getTotalRoll() << std::endl;
}

Die::~Die(){

	// free up memory used by Die
	delete first_die_p;
	delete second_die_p;
}