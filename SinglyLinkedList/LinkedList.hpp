
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.hpp"
#include <iostream>

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
};

template <typename T>
LinkedList<T>::LinkedList(): m_count(0), Head(NULL), Tail(NULL) {}

template <typename T>
Node<T>* LinkedList<T>::Get(int index)
{
  if (index < 0 || index > m_count)
    return -1;

  Node<T>* node = Head;

  for(int i = 0; i < index; i++)
    node = node->Next;

  return node;
}

template <typename T>
void LinkedList<T>::InsertHead(T val)
{
  Node<T> *node = new Node<T>(val);
  node->Next = Head;
  Head = node;

  if(m_count == 0)
    Tail = Head;

  m_count++;
}

template <typename T>
void LinkedList<T>::InsertTail(T val)
{
  if(m_count == 0)
  {
    InsertHead(val);
    return;
  }

  Node<T> *node = new Node<T>(val);
  Tail->Next = node;
  Tail = node;

  m_count++;
}

template <typename T>
void LinkedList<T>::Insert(int index, T val)
{
  if (index < 0 || index > m_count)
    return;

  if (index == 0)
  {
    InsertHead(val);
    return;
  }
  else if (index == m_count)
  {
    InsertTail(val);
    return;
  }

  Node<T>* currNode = Head;
  for (int i = 0; i < index-1; ++i)
    currNode = currNode->Next;

  Node<T>* node = new Node<T>(val);
  node->Next = currNode->Next;
  currNode->Next = node;

  ++m_count;
}

template <typename T>
int LinkedList<T>::Search(T val)
{
  if (m_count == 0)
    return -1;

  int index = 0;
  Node<T>* node = Head;

  while(node->Value != val)
  {
    index++;
    node = node->Next;

    if (node == NULL)
      return -1;
  }
  return index;
}

template <typename T>
void LinkedList<T>::RemoveHead()
{
  if (m_count == 0)
    return;

  Node<T>* node = Head;
  Head = Head->Next;

  delete node;
  m_count--;
}

template <typename T>
void LinkedList<T>::RemoveTail()
{
  if (m_count == 0)
    return;

  if (m_count == 1)
  {
    RemoveHead();
    return;
  }

  Node<T>* prevNode = Head;
  Node<T>* node = Head->Next;
  while(node->Next != NULL)
  {
    prevNode = prevNode->Next;
    node = node->Next;
  }

  prevNode->Next = NULL;
  Tail = prevNode;
  delete node;
  m_count--;
}

template <typename T>
void LinkedList<T>::Remove(int index)
{
  if(m_count == 0)
        return;

  if(index < 0 || index >= m_count)
    return;

  if(index == 0)
  {
    RemoveHead();
    return;
  }
  else if(index == m_count - 1)
  {
    RemoveTail();
    return;
  }

  Node<T>* prevNode = Head;
  for(int i = 0; i < index - 1; ++i)
    prevNode = prevNode->Next;

  Node<T>* node = prevNode->Next;
  Node<T>* nextNode = node->Next;

  prevNode->Next = nextNode;
  delete node;
  m_count--;
    
}

template <typename T>
int LinkedList<T>::Count()
{
  return m_count;
}

template <typename T>
void LinkedList<T>::PrintList()
{
  Node<T>* node = Head;

  while(node != NULL)
  {
    std::cout << node->Value << "->";
    node = node->Next;
  }
  std::cout << "NULL" << std::endl;
}
#endif
