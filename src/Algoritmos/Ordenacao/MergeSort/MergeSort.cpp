#include "MergeSort.h"

// TODO - Remover essa caralhada de comentário horroroso explicando o codigo
// TODO - Tratar para quantidade impar de numeros
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

void MergeSort::obterPrimeiraMetade(int auxiliar1[], int unsortedNumbers[], int size)
{
  for (int i = 0; i < size/2; ++i)
  {
    auxiliar1[i] = unsortedNumbers[i];
  }
}

void MergeSort::obterSegundaMetade(int auxiliar2[], int unsortedNumbers[], int size)
{
  for (int i = size/2; i < size; i++)
  {
    auxiliar2[i - size/2] = unsortedNumbers[i];
  }
}

void MergeSort::sort(int unsortedNumbers[], int size, int sortedNumbers[])
{
  int auxiliar1[size/2];
  int auxiliar2[size/2];
  int arrayf1[size/2];
  int arrayf2[size/2];
  if(size == 1)
  {
    sortedNumbers[0] = unsortedNumbers[0];
  }
  else
  {
    obterPrimeiraMetade(auxiliar1, unsortedNumbers, size);
    obterSegundaMetade(auxiliar2, unsortedNumbers, size);
    sort(auxiliar1, size/2, arrayf1);
    sort(auxiliar2, size/2, arrayf2);
    mergeTwoSortedLists(arrayf1, size/2, arrayf2, size/2, sortedNumbers);
  }
}
