#include <iostream>

#include "./Algoritmos/Ordenacao/SelectionSort/SelectionSort.h"

int main(int argc, char const *argv[])
{
  int numbers[6] = {23, 42, 4, 16, 8, 15};
  SelectionSort *selectionSort = new SelectionSort();
  selectionSort->sort(numbers, 6);
  for (int i = 0; i < 6; i++)
  {
    std::cout << numbers[i] << " ";
  }
  printf("\n");
  return 0;
}
