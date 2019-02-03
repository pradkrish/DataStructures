
#include "Stack.hpp"

template <typename T>
Stack<T>::Stack() : m_count(0), m_top(NULL) {}

template <typename T>
bool Stack<T>::IsEmpty()
{
  return m_count <= 0 ? true: false;
}

template <typename T>
T Stack<T>::Top()
{
  return m_top->Value;
}

template <typename T>
void Stack<T>::Push(T val)
{
  Node<T>* node = new Node<T>(val);
  node->Next = m_top;
  m_top = node;

  m_count++;
}

template <typename T>
void Stack<T>::Pop()
{
  if(IsEmpty())
    return;

  Node<T>* node = m_top;
  m_top = m_top->Next;
  delete node;

  m_count--;
}
