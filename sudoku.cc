/*****************************************************************************
 *
 * Name:	Professor Campbell
 *
 * Date:	October 8, 2017
 *
 * Assignment:	Project Sudoku Board
 *
 * Purpose:	Create a program to solve a Sudoku puzzle
 *
*****************************************************************************/

#include <iostream>
#include "sudokuboard.h"

using namespace std;

sudokuboard board;
stack moves;

int numrepl(int repl, int row, int col) {
  // Replaces number at row, col in board
	if(repl != 9) {

    // Increments replacement value and searches
    // for all possible values that can be placed at row, col
	  for(repl = repl + 1; repl <= 9; repl++) {
	    if(board.canPlace(row, col, repl)) {
	      return repl;
	    }
	  }
	}
	return 0;
}

void getnum(int r, int c, int & num) {
  // Returns lowest number that can be placed at row, col in board
  // Used with mostConstrained function
  num = 0;

  // Searches for all possible values that can be placed
  for(int p = 1; p <= 9; p++)
    if(board.canPlace(r, c, p)) {
      num = p;
      return;
    }
}


void mostConstrained(int & r, int & c, int & num) {
  // Finds most constrained square on grid
  num = 0;

  int counter = 0; // Amount of numbers that can be placed at row, col
  int maxconstrained = 10; // Max numbers that can be placed on spot in grid

  // Searches through grid to see how many numbers can be placed at row, col
  for(int row = 0; row < 9; row++)
    for(int col = 0; col < 9; col++) {
      counter = 0; // Initializes counter to zero on each run
      for(int p = 1; p <= 9; p++) {
        if(board.canPlace(row, col, p)) 
          counter++; 
      }

      if(counter != 0 && counter < maxconstrained) {
        maxconstrained = counter;
        r = row;
        c = col;
      }
    }

  // If maxconstrained has not changed, a most constrained has not been found
  if(maxconstrained == 10) {
    num = 0;
    return;
  }
  getnum(r, c, num);
}

int main() {

  int row = 0; 
  int col = 0; 
  int num = 0;

  // Finds the first constrained square on the board 
  // and changes row, col to that position
  mostConstrained(row, col, num);//, num);
  while(!board.solved()) {

    // If the number returned is not 0, a most constrained has
    // been found and the number may be placed
  	if(num > 0) {
  		board.place(moves, row, col, num);
  		mostConstrained(row, col, num);
    }
    else {
        col = moves.top(); 
        moves.pop();
        row = moves.top(); 
        moves.pop();
        num = board.get(row, col);
        board.replace(row, col, '_');
        num = numrepl(num, row, col); 
    }
  }

  if(board.solved()) {
    board.print();
  }
  else 
    cout << "BOARD NOT SOLVED" << endl;
  return 0;
}


