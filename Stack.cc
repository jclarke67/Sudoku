#include "Stack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Item;

Stack::Node::Node(const Item& value, Node* next) {
  Value = value;
  Next = next;
}

Stack::Stack() {
  Top = NULL;
}

void Stack::push(const Item& item) {
  Top = new Node(item, Top);
  len++;
}

Stack::Node* Stack::copy(Node* head) {
  if(head == NULL)
    return NULL;

  Node* x = copy(Top->Next);
  Node* newOne = new Node(head->Value, x);
  return newOne;
}

void Stack::pop() {
  //assert(!empty());
  
  Node* dead = Top;
  
  Top = Top->Next;

  delete dead;
}

Item Stack::top() const {
  return Top->Value;
}

bool Stack::empty() const {
  if(Top == NULL) {
    return true;

  }
  return false;
}

void Stack::show() const {
  for (Node* p = Top; p != NULL; p = p->Next)
    cout << "[" << p->Value << "]" << endl;
}

void Stack::deleteAll(Node* front) {
  if (front == NULL)
  return;

  deleteAll(front->Next);
  delete front;
}

Stack::~Stack() {
  deleteAll(Top);
}

int Stack::length() {
  
}