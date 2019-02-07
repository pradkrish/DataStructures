
#include <iostream>

using namespace std;

void selectionSort(int arr[], int arrSize)
{
  // store the index of the minimum value in each iteration
  // Iterate outer loop through N-1 elements
  int minIndex;

  for(int i = 0; i < arrSize - 1; ++i)
  {
    // Set the first unsorted element as the minimum value
    // and iterate inner loop through unsorted elements
   
    minIndex = i;

    for(int j = i + 1; j < arrSize; ++j)
    {
      if (arr[j] < arr[minIndex])
	minIndex = j;
    }
    swap(arr[i], arr[minIndex]);
  }
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

  // Sort the array with selection sort
  selectionSort(arr, arrSize);

  cout << "Sorted array : ";
  for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}
