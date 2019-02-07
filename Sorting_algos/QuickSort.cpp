
#include <iostream>

using namespace std;

int Partition(int arr[],int startIndex,int endIndex)
{
  // always choose the start index as pivot
  int pivot = arr[startIndex];
  int middleIndex = startIndex;

  for (int i = startIndex+1; i <= endIndex; ++i)
  {
    if (arr[i] < pivot)
    {
      ++middleIndex;
      swap(arr[i], arr[middleIndex]);
    }
  }

  // swap the value at middleIndex with the rightmost
  // member of the left subarray
  swap(arr[startIndex], arr[middleIndex]);
  return middleIndex;
}

void QuickSort(int arr[],int startIndex,int endIndex)
{
  if (startIndex < endIndex)
  {
    int pivotIndex = Partition(arr, startIndex, endIndex);

    // recursively sort the left subarray
    QuickSort(arr, startIndex, pivotIndex-1);

    // recursively sort the right subarray
    QuickSort(arr, pivotIndex+1, endIndex);
  }
}


int main()
{
  int arr[] = {25, 21, 12, 40, 37, 43, 14, 28};
  int arrSize = sizeof(arr)/sizeof(*arr);
  
  cout << "Unsorted array: ";
  for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
  cout << endl;
  
  QuickSort(arr, 0, arrSize - 1);
  cout << "Sorted array: ";
  for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
  cout << endl;
  
  return 0;
}
