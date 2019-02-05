
#include <iostream>
#include "Queue.cpp"

using namespace std;

int main()
{
  Queue<int> queue = Queue<int>();

  // Enqueue several numbers to the queue
  queue.Enqueue(35);
  queue.Enqueue(91);
  queue.Enqueue(26);
  queue.Enqueue(78);
  queue.Enqueue(44);
  queue.Enqueue(12);

  // list the element of queue
  while(!queue.IsEmpty())
  {
    cout << queue.Front() << " - ";
    queue.Dequeue();
  }
  cout << "END" << endl;

  return 0;
}
