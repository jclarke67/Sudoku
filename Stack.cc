#include <cassert>
#include "stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

typedef int element;

stack::node::node(element data, node* n) {
  value = data;
  next = n;
}


stack::stack() {
  _top = NULL;
}

void stack::push(const element& item) {
  //cout << "PUSH ENTER" << endl;
  _top = new node(item, _top);
  //cout << "PUSH EXIT" << endl;

}

stack::node* stack::copy(node* head) {
  if(head == NULL)
    return NULL;

  node* x = copy(_top->next);
  node* newOne = new node(head->value, x);
  return newOne;

}

void stack::pop() {
  //cout << "POP ENTER" << endl;
  assert(!empty());

  node* dead = _top;
  if(_top -> next)
    _top = _top->next;
  else
    _top = NULL;
  delete dead;
  //cout << "POP EXIT" << endl;


}

element stack::top() const {
  //cout << "TOP ENTER" << endl;
  //cout << "TOP EXIT" << endl;
  assert(!empty());
  return _top->value;


}

bool stack::empty() const {
  //cout << "EMPTY ENTER" << endl;
  if(_top == NULL) {
  //cout << "EMPTY EXIT" << endl;
    return true;

  }
  //cout << "EMPTY EXIT" << endl;
  return false;
}

void stack::show() const {
  //cout << "SHOW ENTER" << endl;

  for (node* p = _top; p != NULL; p = p->next)
    cout << "[" << p->value << "]";
  //cout << "SHOW EXIT" << endl;

  
}


void stack::deleteAll(node* front) {
  //cout << "DELETE ENTER" << endl;

  if (front == NULL)
    //cout << "DELETE EXIT" << endl;

    return;

  deleteAll(front->next);
  delete front;

}

stack::~stack() {

  deleteAll(_top);
}

