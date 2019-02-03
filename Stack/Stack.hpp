#ifndef STACK_H
#define STACK_H

#include "Node.hpp"

template <typename T>
class Stack
{
private:
  int m_count;
  Node<T> * m_top;

public:
  // standard stack operations and a function
  // to check whether stack is empty
  Stack();
  bool IsEmpty();
  T Top();
  void Push(T val);
  void Pop();
};

#endif
