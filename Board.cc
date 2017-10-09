#include "sudokuboard.h"	// Note, this is in "backwards" order to help
#include "stack.h"
#include <iostream>		// Done.
#include <cstdlib>

using namespace std;

stack tempstack;

sudokuboard::sudokuboard() {
  grid[0][0] = '_';
  Build();
}

char sudokuboard::numToChar(int num) {
  char charval = '0' + num;
  return charval;
}

bool sudokuboard::empty(int r, int c) {
  if(grid[r][c] == '_')
    return true;
  return false;
}

void sudokuboard::replace(int r, int c, char a) {
  grid[r][c] = a;

}
void sudokuboard::place(stack& stack, int r, int c, int n) {
  grid[r][c] = numToChar(n);
  stack.push(r);
  stack.push(c);
  
}

void sudokuboard::print() {
  for(int row = 0; row < 9; row++) {
    for(int col = 0; col < 9; col++) {
      cout << grid[row][col];
    }
    cout << endl;
  }
}

int sudokuboard::get(int r, int c) {    // Probably will use a private method
  if (grid[r][c] != '_') {
    int numval = grid[r][c] - '0';   // Also needs to be converted to an int
    return numval;
  }
  return 0;
}

void sudokuboard::remove(int r, int c) {
  grid[r][c] = '_';
  
}

bool sudokuboard::hasRowDuplicate(int c, int num) {
  for(int row = 0; row < 9; row ++) {
    if(grid[row][c] == numToChar(num))
      return true;
  }
  return false;
}

bool sudokuboard::hasColDuplicate(int r, int num) {
  for(int col = 0; col < 9; col++) {
    if(grid[r][col] == numToChar(num)) {
      return true;
    }
  }
  return false;
}

bool sudokuboard::hasBoxDuplicate(int r, int c, int num) {
  r = r/3 * 3;
  c = c/3 * 3;
  for(int row = 0; row < 3; row++)
    for(int col = 0; col < 3; col++)
      if(grid[r + row][c + col] == numToChar(num)) {
        return true;
      }
  return false;
}

bool sudokuboard::canPlace(int r, int c, int n) {
  if (empty(r,c)) {
    if (!hasRowDuplicate(c, n) && !hasColDuplicate(r, n) && !hasBoxDuplicate(r, c, n)) {
      return true;
    }
  }
  return false;
}

bool sudokuboard::solved() {                 // Needs more refining
  for(int row = 0 ; row < 9; row++)
    for(int col = 0 ; col < 9; col++) 
      if(empty(row, col)) 
        return false;
  return true;
}

void sudokuboard::Build() {

  // Builds the grid using a loop for input

  for(int row = 0; row < 9; row++) {
    for(int col = 0; col < 9; col++) {
      char val;
      cin >> val;
      grid[row][col] = val;
    }
  }
}
