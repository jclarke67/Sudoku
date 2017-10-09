#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;


class stack {
 public:
  typedef int element;
  stack();
  void push(const element& item);
  void pop();
  element top() const; // returns the item type top.
  bool empty() const;
  void show() const;
  ~stack();
 private:
  class node {
  public:
    typedef int element; // Adds element as another name for int
    node(element data, node* n);
    element value;
    node * next;
  };

  node * _top;

  void deleteAll(node* front);
  node* copy(node* head);

};

#endif
