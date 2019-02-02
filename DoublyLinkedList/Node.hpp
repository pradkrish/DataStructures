// Node class

#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node
{
public:
  T Value;
  Node<T> *Next;
  Node<T>* Previous;
  Node(T value);
};

template <typename T>
Node<T>::Node(T value): Value(value), Next(NULL), Previous(NULL) {}

#endif
