//Mine class, which inherits from the Cell class

#ifndef MINE_HPP_
#define MINE_HPP_

#include "Cell.hpp"

class Mine: public Cell {
public:
	bool clicked(void);  // see comments on Cell
	void print(void);
};

#endif //MINE_HPP_