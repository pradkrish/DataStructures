#include <iostream>
#include "Deque.cpp"

using namespace std;

int main()
{
    Deque<int> deque = Deque<int>();

    deque.EnqueueFront(26);
    deque.EnqueueBack(78);
    deque.EnqueueBack(44);
    deque.EnqueueFront(91);
    deque.EnqueueFront(35);
    deque.EnqueueBack(12);

    // list the element of queue
    while(!deque.IsEmpty())
    {
      // Get the back (or front) element
      cout << deque.Back() << " - ";

      // Remove the back (or front) element
      deque.DequeueBack();
    }
    cout << "END" << endl;

    return 0;
}
