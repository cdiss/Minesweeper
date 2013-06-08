#include "Mine.hpp"

#include <iostream>
using namespace std;

Mine::Mine() {
	flagsRemaining++;
}

bool Mine::clicked(void) {
	status = CLICKED;
	return false;
}

void Mine::print(void) {
	switch(status) {
		case CLICKED: cout << "X"; break;
		case UNCLICKED: cout << "-"; break;
		case FLAGGED: cout << "!"; break;
		default: cout << "Error in Mine::print()" << endl; break;
	}
}