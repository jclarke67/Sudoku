#include "Board.h"	// Note, this is in "backwards" order to help
#include "Stack.h"
#include <iostream>		// Done.
#include <cstdlib>

using namespace std;

Board::Board() {
  grid[0][0] = '_';
}

char Board::numToChar(int num) {
  char charval = '0' + num;
  return charval;
}

void Board::BoardSetup(int r, int c, char n) {
  grid[r][c] = n;

}

void Board::place(Stack& stack, int r, int c, char n) {
  grid[r][c] = n;
  stack.push(r);
  stack.push(c);
  
}

void Board::print() {     //
  for(int row = 0; row < 9; row++){
    for(int col = 0; col < 9; col++){
      cout << grid[row][col];
    }
    cout << endl;
  }
}

int Board::get(int r, int c) {    // Probably will use a private method
  if (grid[r][c] != '_'){
    int numval = grid[r][c] - '0';        // Also needs to be converted to an int
    return numval;
  }
  return grid[r][c];
}

void Board::remove(int r, int c) {
  grid[r][c] = '_';
  
}

bool Board::hasRowDuplicate(int c, int num) {
  for(int row = 0; row < 9; row ++) {
    if(grid[row][c] == numToChar(num))
      return true;
  }
  return false;
}

bool Board::hasColDuplicate(int r, int num) {
  for(int col = 0; col < 9; col++) {
    if(grid[r][col] == numToChar(num)) {
      return true;
    }
  }
  return false;
}

bool Board::hasBoxDuplicate(int r, int c, int num) {
  r = r/3 * 3;
  c = c/3 * 3;
  for(int row = 0; row < 3; row++)
    for(int col = 0; col < 3; col++)
      if(grid[r + row][c + col] == num) {
        return true;
      }
  return false;
}


bool Board::canPlace(int r, int c, int n) {
  if (grid[r][c] == '_') {
    if (!hasRowDuplicate(c, n) && !hasColDuplicate(r, n) && !hasBoxDuplicate(r, c, n)) {
      return true;
    }
  }
  return false;
}


bool Board::solved() {                 // Needs more refining
  for(int row; row < 9; row++) {
    for(int col; col < 9; col++) {
      if(grid[row][col] == '_') {
        return false;
      }
    }
  }
  return true;
}

void Board::Build() {

  // Builds the grid using a loop for input

  for(int row = 0; row < 9; row++) {
    for(int col = 0; col < 9; col++) {
      char val;
      cin >> val;
      BoardSetup(row, col, val);
    }
  }
}


void Board::setRow(int row) {
  Row = row;
}
void Board::setCol(int col) {
  Col = col;
}
void Board::setNum(int num) {
  Num = num;
}
int Board::getRow() {
  return Row;
}
int Board::getCol() {
  return Col;
}
int Board::getNum() {
  return Num;
}

