
#include <iostream>
#include "Stack.cpp"

int main()
{
  Stack<int> stack = Stack<int>();

  stack.Push(32);
  stack.Push(47);
  stack.Push(18);
  stack.Push(59);
  stack.Push(88);
  stack.Push(91);

  // list the element of stack
  while(!stack.IsEmpty())
  {
    std::cout << stack.Top() << " - ";
    stack.Pop();
  }
  std::cout << "NULL" << std::endl;
  return 0;
}
