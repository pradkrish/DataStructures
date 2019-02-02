#include <iostream>
#include "Node.hpp"
#include "LinkedList.hpp"

int main()
{

  LinkedList<int> linkedList = LinkedList<int>();
  
  linkedList.InsertHead(43);

  linkedList.InsertHead(76);
  linkedList.InsertTail(15);
  linkedList.InsertTail(44);
  linkedList.InsertTail(100);
  linkedList.Insert(3, 48);
  linkedList.PrintList();
  linkedList.Remove(2);
  linkedList.PrintList();
  return 0;
}
