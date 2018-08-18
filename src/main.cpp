#include <iostream>

#include "./Algoritmos/Ordenacao/MergeSort/MergeSort.h"

int main(int argc, char const *argv[])
{
  int numbers[7] = {30, 4, 5, 92, 18, 73, 22};
  MergeSort *mergeSort = new MergeSort();
  mergeSort->sort(numbers, 7);
  for (int i = 0; i < 7; ++i)
  {
    std::cout << numbers[i] << " ";
  }
  return 0;
}
