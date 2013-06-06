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
	void flagged(void); // call this to mark this cell as flagged (or to unflag, if this cell is already flagged). Works properly regardless of whether this cell is currently UNCLICKED, CLICKED (in which case no effect), or FLAGGED.
	virtual bool clicked(void) = 0;  // call this when this cell is clicked
	virtual void print(void) = 0;  // call this to print the cell (as part of the 'SoleSweeper grid)

protected:
	Cell* adjacency_list[8];
};

class Mine: public Cell {
public:
	bool clicked(void);  // see comments on Cell
	void print(void);
};

class NumberCell: public Cell {
public:
	NumberCell();  // sets contents to default value 9, indicating uninitialized. Later must call setContents(). 9 cannot ever be the actual value of a cell in Minesweeper.
	NumberCell(int value);   // no call the setContents() is necessary if this constructor is used.
	void setContents(int value);   // sets contents to the passed value
	int getContents(void);   // returns the current contents.
	bool clicked(void);    // see comments on Cell
	void print(void);
private:
	int contents;
};

#endif