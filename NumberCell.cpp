#include "Cell.hpp"
#include "NumberCell.hpp"

#include <iostream>
using namespace std;

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