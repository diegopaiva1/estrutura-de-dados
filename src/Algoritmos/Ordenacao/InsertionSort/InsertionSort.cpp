#include "InsertionSort.h"

void InsertionSort::sort(int unsortedNumbers[], int size)
{
  int sortedNumbers[6];
  // Consideramos que o primeiro elemento do array ja está ordenado
  sortedNumbers[0] = unsortedNumbers[0];

  int amountOfSortedNumbers = 1;

  // Começamos a iterar a partir do segundo elemento, pois o primeiro já está ordenado
  for (int i = 1; i < size; i++)
  {
    int numberToBeSorted = unsortedNumbers[i];
    for (int j = amountOfSortedNumbers - 1; j >= 0; j--)
    {
      int sortedNumber = sortedNumbers[j];
      if (sortedNumber > numberToBeSorted)
      {
        sortedNumbers[j+1] = sortedNumber;
        if(j == 0)
        {
          sortedNumbers[j] = numberToBeSorted;
        }
      }
      else
      {
        sortedNumbers[j+1] = numberToBeSorted;
        break;
      }
    }
    amountOfSortedNumbers++;
  }

  // TODO -- Isolar esta responsabilidade em uma classe separada
  // Copiando um array para o outro
  for (int i = 0; i < size; i++)
  {
    unsortedNumbers[i] = sortedNumbers[i];
  }
}
