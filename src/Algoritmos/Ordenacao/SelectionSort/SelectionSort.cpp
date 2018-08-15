#include "SelectionSort.h"

void SelectionSort::sort(int unsortedNumbers[], int size)
{
  for (int i = 0; i < size; i++)
  {
    int minimumValueIndex = ArrayUtils::findMinimumValueIndex(unsortedNumbers, size, i);
    ArrayUtils::swapValues(unsortedNumbers, i, minimumValueIndex);
  }
}