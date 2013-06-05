#include <iostream>
using namespace std;

enum clicked_status {
	UNCLICKED,
	CLICKED,
	FLAGGED
};

// abstract base class
class Cell {
public:
	clicked_status status;
	Cell* adjacency_list[8];
	
	Cell();
	void add_adjacent_cell(Cell* adj);    // argument is a Cell pointer to be added to the list of pointers to adjacent Cells.
	void flagged(void) { if(status == UNCLICKED) status = FLAGGED;};
	virtual bool clicked(void) = 0;
	virtual void print(void) = 0;
};

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

class Mine : public Cell {
public:
	Mine() : Cell() { };    // use the Cell() constructor unmodified
	bool clicked(void);
	void print(void);
};

class NumberCell : public Cell {
private:	
	int contents;
public:	
	NumberCell() : Cell() { contents = 9 };    // when constructed with no parameters, use the Cell() constructor and initialize to 9 (garbage value indicating uninitialized)
	NumberCell(int value) : Cell() {contents = value;};    // use the Cell() constructor and then initialize contents
	void setContents(int value) {contents = value;};
	int getContents(void) {return contents;};

	bool clicked(void);
	void print(void);
};

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
		default: cout << "Error in Mine::print(void)" << endl; break;
	}
}

void NumberCell::print(void) {
	switch(status) {
		case CLICKED:
			if (contents == 0) cout << " ";
			else cout << contents;
			break;
		case UNCLICKED: cout << "-"; break;
		case FLAGGED: cout << "!" << endl; break;
		default: cout << "Error in NumberCell::print(void)" << endl; break;
	}
}