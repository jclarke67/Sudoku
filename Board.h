#ifndef BOARD_H
#define BOARD_H
#include "Stack.h"

#include <iostream>

using namespace std;

class Board {
public:
  Board();
  void BoardSetup(int r, int c, char n);
  void place(Stack& stack, int r, int c, char n);    // place numeral n at position (r,c)
  void print();                       // write the board to cout
  int get(int r, int c);              // return the numeral at position (r,c)
  void remove(int r, int c);          // remove the numeral at position (r,c)
  bool canPlace(int r, int c, int n); // true iff the board would allow placing                                        
                                      // n at (r,c).
  bool solved();                      // true if there are no blank spots on the                                       
                                      // board.
  void Build();
  void setRow(int row);
  void setCol(int col);
  void setNum(int num);
  int getRow();
  int getCol();
  int getNum();
  bool hasRowDuplicate(int c, int num);
  bool hasColDuplicate(int r, int num);
  bool hasBoxDuplicate(int r, int c, int num);
  char numToChar(int num);

private:
  char grid[9][9];
  int Row;
  int Col;
  int Num;
    
};

#endif