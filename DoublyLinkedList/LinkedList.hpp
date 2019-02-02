
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.hpp"

template <typename T>
class LinkedList
{
private:
  int m_count;
public:
  // first node in the list
  Node<T>* Head;
  
  // last node in the list
  Node<T>* Tail; 

  // constructor
  LinkedList();

  // Get operation
  Node<T>* Get(int index);

  // Insert operation
  void InsertHead(T val);
  void InsertTail(T val);
  void Insert(int index, T val);

  // Search operation
  int Search(T val);

  // Remove operation
  void RemoveHead();
  void RemoveTail();
  void Remove(int index);

  // Count the number of the elements
  int Count();

  // Print
  void PrintList();
  void PrintListBackward();
};

#endif
