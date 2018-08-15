#include "MergeSort.h"

// TODO - Remover essa caralhada de comentário horroroso explicando o codigo
void MergeSort::mergeTwoSortedLists(int sortedList1[], int size1,
                                    int sortedList2[], int size2,
                                    int mergedList[])
{
  int j = 0; // Iterador da primeira lista
  int k = 0; // Iterador da segunda lista
  for (int i = 0; i < size1 + size2; i++)
  {
    if(sortedList1[j] > sortedList2[k])
    {
      mergedList[i] = sortedList2[k];
      k++;
    }
    else
    {
      mergedList[i] = sortedList1[j];
      j++;
    }
  }
}
