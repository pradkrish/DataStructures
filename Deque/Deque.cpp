
#include "Deque.hpp"

template <typename T>
Deque<T>::Deque() : m_count(0), m_front(NULL), m_back(NULL) {}

template <typename T>
bool Deque<T>::IsEmpty()
{
  return m_count <= 0;
}

template <typename T>
T Deque<T>::Front()
{
  return m_front->Value;
}

template <typename T>
T Deque<T>::Back()
{
  return m_back->Value;
}

template <typename T>
void Deque<T>::EnqueueFront(T val)
{
  Node<T>* node = new Node<T>(val);
  node->Next = m_front;

  if (m_front != NULL)
    m_front->Previous = node;
  
  m_front = node;

  if (m_count == 0)
    m_back = m_front;

  m_count++;
}

template <typename T>
void Deque<T>::EnqueueBack(T val)
{
  if(m_count == 0)
  {
    EnqueueFront(val);
    return;
  }

  Node<T> * node = new Node<T>(val);
  m_back->Next = node;
  node->Previous = m_back;
  m_back = node;

  m_count++;
}

template <typename T>
void Deque<T>::DequeueFront()
{
  if(m_count == 0)
    return;

  Node<T> * node = m_front;
  m_front = m_front->Next;

  if(m_front != NULL)
    m_front->Previous = NULL;

  delete node;
  m_count--;
}

template <typename T>
void Deque<T>::DequeueBack()
{
  if(m_count == 0)
    return;

  if(m_count == 1)
  {
    DequeueFront();
    return;
  }

  Node<T> * node = m_back;
  m_back = m_back->Previous;
  m_back->Next = NULL;
  delete node;

  m_count--;
}





