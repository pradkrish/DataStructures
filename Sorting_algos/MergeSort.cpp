
#include <iostream>

using namespace std;

void Merge(int arr[],int startIndex,int middleIndex,int endIndex)
{
    int totalElements = endIndex - startIndex + 1;
    int *tempArray = new int[totalElements];
    int leftIndex = startIndex;
    int rightIndex = middleIndex + 1;

    // Index of merged array
    int mergedIndex = 0;

    while (leftIndex <= middleIndex && rightIndex <= endIndex)
    {
      if(arr[leftIndex] <= arr[rightIndex])
      {
	// Store the left subarray's element
	// if it's lower than the right one
	// and go to next left subarray index
	tempArray[mergedIndex] = arr[leftIndex];
	++leftIndex;
      }
      else
      {
	tempArray[mergedIndex] = arr[rightIndex];
	++rightIndex;
      }
      ++mergedIndex;
    }

    // If there're any remaining element in left or right subarray
    // that is not stored to merged array yet
    while (leftIndex <= middleIndex)
    {
      tempArray[mergedIndex] = arr[leftIndex];
      ++leftIndex;
      ++mergedIndex;
    }

    while (rightIndex <= endIndex)
    {
      tempArray[mergedIndex] = arr[rightIndex];
      ++rightIndex;
      ++mergedIndex;
    }

    // After merging arrays copy the elements
    //to the original array before deleting
    // temporaray array
    
    for (int i = 0; i < totalElements; ++i)
    {
      arr[startIndex + i] = tempArray[i];
    }

    delete[] tempArray;
}

void MergeSort(int arr[], int startIndex, int endIndex)
{
  if (startIndex < endIndex)
  {
    int middleIndex = (startIndex + endIndex) / 2;

    // sort left subarray
    MergeSort(arr, startIndex, middleIndex);
    //sort right subarray
    MergeSort(arr, middleIndex+1, endIndex);

    // merge the left and right subarray
    Merge(arr, startIndex, middleIndex, endIndex);
  }
}

int main()
{
  int arr[] = {7, 1, 5, 9, 3, 6, 8, 2};
  int arrSize = sizeof(arr)/sizeof(*arr);

  cout << "Unsorted array: ";
  for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
  cout << endl;
  
  // Sort the array with MergeSort algorithm
  MergeSort(arr, 0, arrSize - 1);

  cout << "Sorted array: ";
  for (int i=0; i < arrSize; ++i)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}
