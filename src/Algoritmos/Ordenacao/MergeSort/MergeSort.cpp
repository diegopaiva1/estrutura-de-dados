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
    // Se a segunda lista ja foi toda percorrida e a primeira não, então basta inserir os elementos
    // da primeira lista na mergedList
    if(k == size2 && j < size1)
    {
      mergedList[i] = sortedList1[j];
      j++;
    }
    // Se a primeira lista ja foi toda percorrida e a segunda não, então basta inserir os elementos
    // da segunda lista na mergedList
    else if(j == size1 && k < size2)
    {
      mergedList[i] = sortedList2[k];
      k++;
    }
    // Senão, continue comparando os elementos e os inserindo
    else {
      if(sortedList2[k] < sortedList1[j])
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
}
