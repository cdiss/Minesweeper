#include "Cell.hpp"

#include <iostream>
using namespace std;

Cell::Cell() {    // constructor for the Cell class
	status = UNCLICKED; 
	for (int i=0; i<8; i++) {
		adjacency_list[i] = NULL;
	}
};

void Cell::add_adjacent_cell(Cell* adj) {
	int i = 0;
	bool done = false;
	while(!done) {
		if (adjacency_list[i] == NULL) {
			adjacency_list[i] = adj;
			done = true;
		}
		i++;
	}
}

int Cell::flagsRemaining = 0;

void Cell::flagged(void) {
	if(flagsRemaining <= 0) {return;}   // don't flag the cell if they have no flags left
	switch(status) {
		case UNCLICKED: status = FLAGGED; break;
		case CLICKED: break;
		case FLAGGED: status = UNCLICKED; break;
		default: cout << "Error in Cell::flagged()" << endl;
	}
	flagsRemaining--;
}

int Cell::getNumRemaining(void) {
	return flagsRemaining;
}