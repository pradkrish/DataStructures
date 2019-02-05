#ifndef DEQUE_H
#define DEQUE_H

#include "Node.hpp"

template <typename T>
class Deque
{
private:
  int m_count;
  Node<T> * m_front;
  Node<T> * m_back;

public:
  // Standard Deque operations
  Deque();
  bool IsEmpty();
  T Front();
  T Back();
  void EnqueueFront(T val);
  void EnqueueBack(T val);
  void DequeueFront();
  void DequeueBack();
};

#endif
