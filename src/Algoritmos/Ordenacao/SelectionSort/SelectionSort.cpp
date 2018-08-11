#include "SelectionSort.h"

void SelectionSort::sort(int unsortedNumbers[], int size)
{
  int sortedNumbersAmount = 0;

  for (int i = 0; i < size; i++)
  {
    int minimumValue = findMinimumValue(unsortedNumbers, size, i);
    int minimumValueIndex = findMinimumValueIndex(unsortedNumbers, size, i);

    if(minimumValue < unsortedNumbers[i])
    {
      swapValues(unsortedNumbers, i, minimumValueIndex);
    }
    sortedNumbersAmount++;
  }
}

int SelectionSort::findMinimumValue(int array[], int size, int index)
{
  int minimumValue = array[index];
  for (int i = index + 1; i < size; i++)
  {
    if(array[i] < minimumValue)
    {
      minimumValue = array[i];
    }
  }
  return minimumValue;
}

int SelectionSort::findMinimumValueIndex(int array[], int size, int index)
{
  int minimumValue = array[index];
  int minimumValueIndex = index;
  for (int i = index + 1; i < size; i++)
  {
    if(array[i] < minimumValue)
    {
      minimumValue = array[i];
      minimumValueIndex = i;
    }
  }
  return minimumValueIndex;
}

void SelectionSort::swapValues(int array[], int firstIndex, int secondIndex)
{
  int temp = array[firstIndex];
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = temp;
}
