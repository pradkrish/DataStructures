#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main()
{
  LinkedList<int> linkedList = LinkedList<int>();

  linkedList.InsertHead(43);
  linkedList.InsertHead(76);
  linkedList.InsertTail(15);
  linkedList.InsertTail(44);
  
  cout << "Print Backwards:" << endl;
  linkedList.PrintListBackward();
  cout << endl;

  linkedList.Insert(4, 100);
  linkedList.Insert(3, 48);
  linkedList.Insert(0, 22);
  cout << "Print Backwards:" << endl;
  linkedList.PrintListBackward();
  cout << endl;

  return 0;
}
