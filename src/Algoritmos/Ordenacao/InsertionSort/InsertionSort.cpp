#include "InsertionSort.h"

void InsertionSort::sort(int unsortedNumbers[], int size)
{
  // Consideramos que o primeiro número do array ja está ordenado
  int amountOfSortedNumbers = 1;

  // Portanto, começamos iterando pelo segundo número
  for (int i = 1; i < size; i++)
  {
    int numberToBeSorted = unsortedNumbers[i];

    // Indice para acessar elementos já ordenados
    int j = amountOfSortedNumbers - 1;

    while(j >= 0 && unsortedNumbers[j] > numberToBeSorted)
    {
      // Arredamos uma posição para a direita
      unsortedNumbers[j+1] = unsortedNumbers[j];
      j--;
    }
    // Inserimos o número
    unsortedNumbers[j+1] = numberToBeSorted;

    amountOfSortedNumbers++;
  }
}
