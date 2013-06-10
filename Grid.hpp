#ifndef GRID_HPP_
#define GRID_HPP_

#include "Cell.hpp"
#include "Mine.hpp"
#include "NumberCell.hpp"

#include <vector>
using namespace std;

class Grid {

public:
  /*
   * Default constructor:
   * Creates a x by y grid (given input), randomly places mines, 
   * and calculates numbers
   *
   * @param x - grid width size
   * @param y - grid height size
   * @param numOfMines - number of mines to be placed in grid
   */
  Grid(int x, int y, int numOfMines);
  
  bool click(int x, int y);
  void flag(int x, int y);
    
  /*
   * printSelf - calls the print method of each cell
   *
   * @param x - grid width size, passed in from constructor
   * @param y - grid height size, passed in from constructor
   */
  void printSelf(void);
    
  bool hasWon(void);
    
protected:
  //the cells, as a 2D array of pointers
  vector<vector<Cell*>>* cellGrid;

  int xSize, ySize;
};

#endif //GRID_HPP_