//Mine class, which inherits from the Cell class

#ifndef NUMBERCELL_HPP_
#define NUMBERCELL_HPP_

#include "Cell.hpp"

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

#endif //NUMBERCELL_HPP_