#include "ArrayUtils.h"

// TODO - Tratar exceções para todos os métodos

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

void ArrayUtils::copyArrayValuesIntoAnotherArray(int arrayToCopyValuesFrom[], int arrayToReceiveValues[],
                                                 int startingIndex, int lastIndex)
{
  for (int i = startingIndex; i <= lastIndex; i++)
  {
    arrayToReceiveValues[i - startingIndex] = arrayToCopyValuesFrom[i];
  }
}
