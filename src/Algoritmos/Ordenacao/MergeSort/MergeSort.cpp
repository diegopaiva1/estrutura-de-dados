#include "MergeSort.h"

void MergeSort::sort(int unsortedNumbers[], int size)
{
  int sortedNumbers[size];
  if(size == 1)
  {
    // Uma lista com um único elemento já está naturalmente ordenada
    sortedNumbers[0] = unsortedNumbers[0];
  }
  else
  {
    int firstSliceSize;
    int secondSliceSize;
    if(sizeIsEven(size))
    {
      firstSliceSize = size/2;
      secondSliceSize = size/2;
    }
    else
    {
      // Ex: Array de tamanho 17 será divido em duas partições de tamanhos 8 e 9
      firstSliceSize = (size - 1)/2;
      secondSliceSize = size - firstSliceSize;
    }
    int firstSlice[firstSliceSize];
    int secondSlice[secondSliceSize];
    ArrayUtils::copyArrayValuesIntoAnotherArray(unsortedNumbers, firstSlice, 0, firstSliceSize - 1);
    ArrayUtils::copyArrayValuesIntoAnotherArray(unsortedNumbers, secondSlice, firstSliceSize, size - 1);
    sort(firstSlice, firstSliceSize);
    sort(secondSlice, secondSliceSize);
    generateSortedArrayByMergingTwoSortedArrays(firstSlice, firstSliceSize,
                                                secondSlice, secondSliceSize,
                                                sortedNumbers);
  }
  ArrayUtils::copyArrayValuesIntoAnotherArray(sortedNumbers, unsortedNumbers, 0, size - 1);
}

bool MergeSort::sizeIsEven(int size)
{
  return size % 2 == 0;
}

void MergeSort::generateSortedArrayByMergingTwoSortedArrays(int sorted1[], int size1,
                                                            int sorted2[], int size2,
                                                            int merged[])
{
  int firstArrayIterator = 0;
  int secondArrayIterator = 0;
  for (int i = 0; i < size1 + size2; i++)
  {
    if(arrayWasFullyCovered(firstArrayIterator, size1) && !arrayWasFullyCovered(secondArrayIterator, size2))
    {
      // Basta inserir em merged os elementos do array que não foi todo percorrido
      merged[i] = sorted2[secondArrayIterator];
      secondArrayIterator++;
    }
    else if(arrayWasFullyCovered(secondArrayIterator, size2) && !arrayWasFullyCovered(firstArrayIterator, size1))
    {
      merged[i] = sorted1[firstArrayIterator];
      firstArrayIterator++;
    }
    else {
      // Continuamos comparando os elementos e os inserindo em merged
      if(sorted2[secondArrayIterator] < sorted1[firstArrayIterator])
      {
        merged[i] = sorted2[secondArrayIterator];
        secondArrayIterator++;
      }
      else
      {
        merged[i] = sorted1[firstArrayIterator];
        firstArrayIterator++;
      }
    }
  }
}

bool MergeSort::arrayWasFullyCovered(int iterator, int size)
{
  return iterator >= size;
}
