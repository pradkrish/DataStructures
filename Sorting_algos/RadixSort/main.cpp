#include <iostream>
#include "Queue.cpp"

using namespace std;

void RadixSort(int arr[], int arrSize)
{
  // Create ten buckets for each digits (0 - 9)
  // Find the largest element and iterate through
  // the array until the array is sorted
  Queue<int>* buckets = new Queue<int>[10];
  int largestElement = arr[0];
  for(int i = 0; i < arrSize; ++i)
  {
    if (largestElement < arr[i])
      largestElement = arr[i];
  }

  for(int exp = 1; largestElement/exp > 0; exp *= 10)
  {
    cout << largestElement/exp <<endl;
    for(int i = 0; i < arrSize; ++i)
      buckets[(arr[i]/exp)%10].Enqueue(arr[i]);

    int counter = 0;
    for(int i = 0; i < 10; ++i)
    {
      while(!buckets[i].IsEmpty())
      {
	arr[counter++] = buckets[i].Front();
	buckets[i].Dequeue();
      }
    }
  }
}

int main()
{
  cout << "Radix Sort" << endl;

  // Initialize a new array
  int arr[] = {429, 3309, 65, 7439, 12, 9954, 30, 4567, 8, 882};
  int arrSize = sizeof(arr)/sizeof(*arr);

  cout << "Unsorted array: ";
  for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
  cout << endl;

  RadixSort(arr, arrSize);

  cout << "Sorted array: ";
  for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}
