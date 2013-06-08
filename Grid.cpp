#include "Grid.hpp"
#include <ctime>
#include <vector>

#include <iostream>
using namespace std;

Grid::Grid(int x, int y, int numOfMines) {
  
  int numOfCells = x*y;

  //create cell array with given number of cells
  //to be used in configuration of mines
  //int *cellArr = new int[numOfCells]
  vector< vector<int> > grid(x, y);

  //loop through cell array, initializing each to 0
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < y; j++) {
      grid[i][j] = 0;
    }
  }

  //seed rand number to the current time
  srand(time(NULL));
  int randNum;
  int randRow;
  int randCol;

  //generate random number between 0 to number of cells;
  //will be used to place mines randomly in the array of cells
  for(int i = 0; i < numOfMines; i++) {
    do {
      randNum = rand()%(numOfCells);
      randRow = randNum % x;
      randCol = (int)randNum / x;
    } while(grid[randRow][randCol] == -1); //while position not already taken
  
    grid[randRow][randCol] = -1;
  }

  //after mines are placed randomly in array, have to calculate what each cell's number is
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < y; j++) {
      if(grid[i][j] == -1) {
        try {
          if(grid.at(i-1).at(j-1) != -1) { grid.at(i-1).at(j-1)++; }
        } catch (out_of_range) {
        }
        try {
          if(grid.at(i-1).at(j) != -1) { grid.at(i-1).at(j)++; }
        } catch (out_of_range) {
        }
        try {
          if(grid.at(i-1).at(j+1) != -1) { grid.at(i-1).at(j+1)++; }
        } catch (out_of_range) {
        }
        try {
          if(grid.at(i).at(j-1) != -1) { grid.at(i).at(j-1)++; }
        } catch (out_of_range) {
        }
        try {
          if(grid.at(i).at(j+1) != -1) { grid.at(i).at(j+1)++; }
        } catch (out_of_range) {
        }
        try {
          if(grid.at(i+1).at(j-1) != -1) { grid.at(i+1).at(j-1)++; }
        } catch (out_of_range) {
        }
        try {
          if(grid.at(i+1).at(j) != -1) { grid.at(i+1).at(j)++; }
        } catch (out_of_range) {
        }
        try {
          if(grid.at(i+1).at(j+1) != -1) { grid.at(i+1).at(j+1)++; }
        } catch (out_of_range) {
        }
      }
    }
  }

  cellGrid = new vector< vector<Cell*> >(x, y);

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (grid[i][j] == -1) {
        cellGrid->at(i).at(j) = new Mine;
      } else {
        cellGrid->at(i).at(j) = new NumberCell(grid[i][j]);
      }
    }
  }

  //print grid
  printSelf(x, y);

}

void Grid::printSelf(int x, int y) {
  //array of chars representing letters of the alphabet (max size 25)
  char alph[25] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                   'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                   's', 't', 'u', 'v', 'w', 'x', 'y'};
  
  //print horizontal heading (numbers)
  cout << "  ";
  for(int i = 0; i < x; i++) {
    cout << " " << i;
  }
  cout << endl;

  //print vertical heading (letters, from char alph array)
  for(int j = 0; j < y; j++) {
    cout << alph[j];
    for(int k = 0; k < (x*y); k++) {
      cout << " ";
      //print method for each individual cell
      cellGrid->at(j).at(k)->print(); 
    }
  }
}