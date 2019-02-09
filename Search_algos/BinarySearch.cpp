
// Standard binary search implementation using recursion
// We assume that we are provided with a sorted array
#include <iostream>

using namespace std;

int binarySearch(int arr[], int startIndex, int endIndex, int val)
{
  if (startIndex <= endIndex)
  {
    int middleIndex = startIndex + (endIndex - startIndex)/2;

    if(arr[middleIndex] == val)
    {
      return middleIndex;
    }
    else if(arr[middleIndex] > val)
    {
      return binarySearch(arr, startIndex, middleIndex - 1, val);
    }
    else
    {
      return binarySearch(arr, middleIndex + 1, endIndex, val);
    }
  }
  return -1;
}

int main()
{
  cout << "Binary Search" << endl;

  // Array to search
  int arr[] = {3, 8, 11, 15, 16, 23, 28, 30, 32, 39, 42, 44, 47, 48, 50};
  int arrSize = sizeof(arr)/sizeof(*arr);

  // value to be searched
  int Value = 28;

  // Find the searched value using Binary Search
  int i = binarySearch(arr, 0, arrSize - 1, Value);

  if(i != -1)
    cout << Value << " is found in index " << i << endl;
  else
    cout << "Could not find value " << Value << endl;

  return 0;
}

