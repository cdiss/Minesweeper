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
	virtual bool clicked(void) = 0;  // call this when this cell is clicked. Returns false if the cell was a mine, true if the cell was 'safe'.
	virtual void print(void) = 0;  // call this to print the cell (as part of the 'SoleSweeper grid)

	static int getNumRemaining(void);  // this tells you how many flags have not been used

protected:
	Cell* adjacency_list[8];
	static int flagsRemaining;
};

#endif //CELL_HPP_
