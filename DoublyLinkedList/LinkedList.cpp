
#include <iostream>
#include "Node.hpp"
#include "LinkedList.hpp"


template <typename T>
LinkedList<T>::LinkedList()
    : m_count(0), Head(NULL), Tail(NULL) {}

template <typename T>
Node<T> * LinkedList<T>::Get(int index)
{

  if(index < 0 || index > m_count)
    return NULL;

  Node<T> * node = Head;

  for(int i = 0; i < index; ++i)
    node = node->Next;
  
  return node;
}

template <typename T>
void LinkedList<T>::InsertHead(T val)
{
  
  Node<T> * node = new Node<T>(val);
  node->Next = Head;

  if(Head != NULL)
    Head->Previous = node;

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

  Node<T> * node = new Node<T>(val);
  Tail->Next = node;
  node->Previous = Tail;
  Tail = node;
  
  m_count++;
}

template <typename T>
void LinkedList<T>::Insert(int index, T val)
{
  if(index < 0 || index > m_count)
    return;

  if(index == 0)
  {
    InsertHead(val);
    return;
  }
  else if(index == m_count)
  {
    InsertTail(val);
    return;
  }
  
  Node<T> * prevNode = Head;

  for(int i = 0; i < index - 1; ++i)
    prevNode = prevNode->Next;

  Node<T> * nextNode = prevNode->Next;
  Node<T> * node = new Node<T>(val);
  node->Next = nextNode;
  node->Previous = prevNode;
  prevNode->Next = node;
  nextNode->Previous = node;

  m_count++;
}

template <typename T>
int LinkedList<T>::Search(T val)
{
  if(m_count == 0)
    return -1;

  int index = 0;
  Node<T> * node = Head;

  while(node->Value != val)
  {
    index++;
    node = node->Next;
    if(node == NULL)
      return -1;
  }
  return index;
}

template <typename T>
void LinkedList<T>::RemoveHead()
{
  if(m_count == 0)
    return;

  Node<T> * node = Head;
  Head = Head->Next;

  delete node;

  if(Head != NULL)
    Head->Previous = NULL;

  m_count--;
}

template <typename T>
void LinkedList<T>::RemoveTail()
{
  if(m_count == 0)
    return;

  if(m_count == 1)
  {
    RemoveHead();
    return;
  }

  Node<T> * node = Tail;
  Tail = Tail->Previous;
  Tail->Next = NULL;

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

  Node<T> * prevNode = Head;
  for(int i = 0; i < index - 1; ++i)
    prevNode = prevNode->Next;

  Node<T> * node = prevNode->Next;
  Node<T> * nextNode = node->Next;
  prevNode->Next = nextNode;
  nextNode->Previous = prevNode;

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
  Node<T> * node = Head;

  while(node != NULL)
  {
    std::cout << node->Value << " -> ";
    node = node->Next;
  }

  std::cout << "NULL" << std::endl;
}

template <typename T>
void LinkedList<T>::PrintListBackward()
{
  Node<T> * node = Tail;

  while(node != NULL)
  {
    std::cout << node->Value << " -> ";
    node = node->Previous;
  }

  std::cout << "NULL" << std::endl;
}
