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

NumberCell::NumberCell() {
	contents = 9;
}

NumberCell::NumberCell(int value) {
	contents = value;
}

void NumberCell::setContents(int value) {
	contents = value;
}

int NumberCell::getContents(void) {
	return contents;
}

bool Mine::clicked(void) {
	status = CLICKED;
	return false;
}

bool NumberCell::clicked(void) {
	status = CLICKED;
	if (contents == 0) {    // if cell is blank
		for (int i=0; i<8; i++) {
			if (adjacency_list[i] != NULL) {    // if there is an entry in this position
				adjacency_list[i]->clicked();   // 'click' all adjacent cells if cell was blank
			}
		}
	}
	return true;
}

void Mine::print(void) {
	switch(status) {
		case CLICKED: cout << "X"; break;
		case UNCLICKED: cout << "-"; break;
		case FLAGGED: cout << "!"; break;
		default: cout << "Error in Mine::print()" << endl; break;
	}
}

void NumberCell::print(void) {
	switch(status) {
		case CLICKED:
			if (contents == 0) cout << " ";
			else cout << contents;
			break;
		case UNCLICKED: cout << "-"; break;
		case FLAGGED: cout << "!"; break;
		default: cout << "Error in NumberCell::print()" << endl; break;
	}
}
