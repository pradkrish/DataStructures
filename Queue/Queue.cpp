
#include "Queue.hpp"

template <typename T>
Queue<T>::Queue() : m_count(0), m_front(NULL), m_back(NULL) {}

template <typename T>
bool Queue<T>::IsEmpty()
{
  return m_count <= 0;
}

template <typename T>
T Queue<T>::Front()
{
  return m_front->Value;
}

template <typename T>
void Queue<T>::Enqueue(T val)
{
  Node<T> * node = new Node<T>(val);

  if(m_count == 0)
  {
    node->Next = NULL;
    m_front = node;
    m_back = m_front;
  }
  else
  {
    m_back->Next = node;
    m_back = node;
  }
  m_count++;
}

template <typename T>
void Queue<T>::Dequeue()
{
  if(m_count == 0)
    return;

  Node<T> * node = m_front;
  m_front = m_front->Next;
  delete node;

  m_count--;
}


