#ifndef STACK_H
#define STACK_H
#include <iostream>
//#include "SudokuBoard.h"

using namespace std;

class Stack {
public:
  typedef int ItemTy;
  Stack();
  void push(const ItemTy& item);
  void pop();
  ItemTy top() const; // returns the item type top.
  bool empty() const;
  void show() const;
  ~Stack();
  int length();
private:
  class Node {
  public:
    typedef int ItemTy; // Adds ItemTy as another name for int
    Node(const ItemTy & value, Node* next = NULL);
    ItemTy Value;
    Node * Next;
  };
  
  Node * Top;
  void deleteAll(Node* front);
  Node* copy(Node* head);
  int len;
  
};

#endif

//SUDOKU PUZZLE SOLVER