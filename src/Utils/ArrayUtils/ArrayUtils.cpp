#include "ArrayUtils.h"

int ArrayUtils::findMinimumValueIndex(int array[], int size, int startingIndex = 0)
{
  int minimumValueIndex = startingIndex;
  int minimumValue = array[startingIndex];
  for (int i = startingIndex; i < size; i++)
  {
    if(array[i] < minimumValue)
    {
      minimumValue = array[i];
      minimumValueIndex = i;
    }
  }
  return minimumValueIndex;
}

void ArrayUtils::swapValues(int array[], int firstIndex, int secondIndex)
{
  int temp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = temp;
}
