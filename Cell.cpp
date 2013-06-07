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

void Cell::flagged(void) {
	switch(status) {
		case UNCLICKED: status = FLAGGED; break;
		case CLICKED: break;
		case FLAGGED: status = UNCLICKED; break;
		default: cout << "Error in Cell::flagged()" << endl;
	}
}