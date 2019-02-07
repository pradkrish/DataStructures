
#include <iostream>

using namespace std;

void bubbleSort(int arr[], int arrSize)
{
  // A flag for swapping element. If there is at least two elements to be
  // swapped, it will be true.
  // The # of iterations will decrease every time one element has been sorted
  bool isSwapped;
    
  int unsortedElements = arrSize;
  do
  {
    isSwapped = false;
    for(int i = 0; i < unsortedElements - 1; ++i)
    {
      if (arr[i] > arr[i+1])
      {
	swap(arr[i], arr[i+1]);
	isSwapped = true;
      }
    }
    --unsortedElements;
  }
  while(isSwapped);
}

int main()
{
  int arr[] {53, 31, 36, 48, 10, 28};
  int arrSize = sizeof(arr)/sizeof(*arr);

  // Display the unsorted array
  cout << "Unsorted array: ";
  for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
  cout << endl;

  // Sort the array with bubble sort
  bubbleSort(arr, arrSize);

  cout << "Sorted array : ";
  for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}
