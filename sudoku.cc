/*****************************************************************************
 *
 * Name:	Professor Bailey
 *
 * Date:	February 24, 2017
 *
 * Assignment:	Project Sudoku Board
 *
 * Purpose:	Create a program to solve a Sudoku puzzle
 *
*****************************************************************************/

#include "Board.h"	// Note, this is in "backwards" order to help
#include "Stack.h"		// identify implicit dependencies. Reverse when
#include <iostream>		// Done.
#include <cstdlib>

using namespace std;

Stack moves;     // Creates variable for board stack to store board moves
Board board;       // Creates sudoku board

/*
void backtracking() {
  int row = moves.top();
  moves.pop();
  int col = moves.top();
  moves.pop();

  int currint = board.get(row, col);
  for(int num = currint + 1; num <= 9; num++) {
    if(board.canPlace(row, col, num)) {
      board.place(moves, row, col, num);
      return;
    }
   
    if(num == 9) {
      board.remove(row, col);
      backtracking();
    }
  }       
}


bool mostConstrained(int r, int c, int num) {
  int counter = 0;
  int maxconstrained = 10;
  for(int row = 0; row < 9; row++)
    for(int col = 0; col < 9; col++)
      if(board.get(row, col) == '_') {
        counter = 0;
        for(num = 1; num <= 9; num++)
          if(board.canPlace(row, col, num))
            counter++;
        if(!counter == 0)
          if(counter < maxconstrained) {
            maxconstrained = counter;
            board.setRow(row);
            board.setCol(col);
            board.setNum(num); 
          }
      }
  return (maxconstrained < 10);
}
*/

void print(int x) {
  cout << x << endl;
}

int main() {
  
  int p;
  //board.place(moves, 1, 4, "x");
  //string g = board.get(1, 4);
  //cout << string << endl;
  //int g[6] = {1, 2, 3, 4, 5, 6};
  for(int x = 0; x < 10; x++) {
    moves.push(x);
    p = moves.top();
    moves.pop();
  }
  print(p);




  /*
  board.setRow(0);
  board.setCol(0);
  board.setNum(0);
  board.Build();

  while(board.solved() == false) {
    if(mostConstrained(board.getRow(), board.getCol(), board.getNum()))
      board.place(moves, board.getRow(), board.getCol(), board.getNum());
    else
      board.place(moves, board.getRow(), board.getCol(), board.getNum());      
      backtracking();
    }

  if(board.solved() != false)
    board.print();
  else 
    cout << "BOARD NOT SOLVED" << endl;
*/
  /* This is to test stack 

     Stack stack; 
     stack.push(2);
     stack.push(3);
     stack.push('m'+'0');
     stack.pop();
     stack.pop();
     int x = stack.top();
     stack.show();
     cout << stack.empty() << endl;
     cout << x << endl;
  */
  // board.print();


  return 0;
}
