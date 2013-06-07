#ifndef CELL_HPP_
#define CELL_HPP_

enum clicked_status {
	UNCLICKED,
	CLICKED,
	FLAGGED
};

// abstract base class
class Cell {

public:
	// instance variables
	clicked_status status;
	
	// methods
	Cell();
	void add_adjacent_cell(Cell* adj); // argument is a Cell pointer to be added to the list of pointers to adjacent Cells.
	void flagged(void); // call this to mark this cell as flagged (or to unflag, if this cell is already flagged).
                      // Works properly regardless of whether this cell is currently UNCLICKED, CLICKED (in which case no effect), or FLAGGED.
	virtual bool clicked(void) = 0;  // call this when this cell is clicked
	virtual void print(void) = 0;  // call this to print the cell (as part of the 'SoleSweeper grid)

protected:
	Cell* adjacency_list[8];
};

#endif //CELL_HPP_