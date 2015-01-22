/*
	dice.cpp
	Andrew Rempe

	Implements the Die class defined in Die.h
*/

#include "dice.h"
#include <iostream>
#include <stdlib.h>

Dice::Dice() {

	// give the dice some initial values
	first_die = 0;
	second_die = 0;

	// seed the random number generator
	srand(time(NULL));
}

void Dice::roll() {

	// choose a random number from 1-6 and assign to dice
	first_die = (rand() % 6) + 1;
	second_die = (rand() % 6) + 1;
}

int Dice::getTotal() {

	// returns total value
	return first_die + second_die;
}

void Dice::print() {

	// print individual and total roll
	std::cout << first_die << " + " << second_die << " = " << getTotal() << std::endl;
}