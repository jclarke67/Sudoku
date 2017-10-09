#ifndef sudokuboard_H
#define sudokuboard_H
#include "stack.h"

#include <iostream>

using namespace std;

class sudokuboard {
public:
  sudokuboard();
  void place(stack& stack, int r, int c, int n);    // place numeral n at position (r,c)
  void replace(int r, int c, char a);
  void print();                       // write the board to cout
  int get(int r, int c);              // return the numeral at position (r,c)
  void remove(int r, int c);          // remove the numeral at position (r,c)
  bool canPlace(int r, int c, int n); // true iff the board would allow placing                                        // n at (r,c).
  bool solved();                      // true if there are no blank spots on the   
  bool empty(int r, int c);                                    // board.
  void Build();
  void setRow(int row);
  void setCol(int col);
  void setNum(int num);
  int getRow();
  int getCol();
  int getNum();
  char numToChar(int num);


private:
  char grid[9][9];
  int Row;
  int Col;
  int Num;
  bool hasRowDuplicate(int c, int num);
  bool hasColDuplicate(int r, int num);
  bool hasBoxDuplicate(int r, int c, int num);

    
};

#endif
