/*
	dice.h
	Andrew Rempe

	Outlines the Die class
*/

#ifndef dice_H
#define dice_H

#include <string>

class Dice {

	// stores values from roll()
	int first_die;
	int second_die;

	// strings for printing dice faces
	std::string dice_output[6][3] = {

		{ "     ", "  *  ", "     " },	// one
		{ "*    ", "     ", "    *" },	// two
		{ "*    ", "  *  ", "    *" },	// three
		{ "*   *", "     ", "*   *" },	// four
		{ "*   *", "  *  ", "*   *" },	// five
		{ "*   *", "*   *", "*   *" }	// six
	};

public:

	// constructor
	Dice();

	// assigns random values 1-6 to first_die and second_die
	void roll();

	// returns first_die + second_die
	int getTotal();

	// prints the outcome of the roll to the screen
	void print();
};

#endif