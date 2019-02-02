#include <iostream>
#include "LinkedList.cpp"

int main()
{

  LinkedList<int> linkedList = LinkedList<int>();
  
  linkedList.InsertHead(43);
  linkedList.InsertHead(76);
  linkedList.InsertTail(15);
  linkedList.InsertTail(44);
  linkedList.InsertTail(100);
  linkedList.Insert(3, 48);
  linkedList.PrintList(); // 76->43->15->48->44->100->NULL
  linkedList.Remove(2);
  linkedList.PrintList(); // 76->43->48->44->100->NULL
  return 0;
}
