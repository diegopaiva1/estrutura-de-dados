#include <iostream>

#include "./Algoritmos/Ordenacao/MergeSort/MergeSort.h"

int main(int argc, char const *argv[])
{
  int numbers[9] = {9, 90, 39, 10, 67, 19, 11, 210, 119};
  MergeSort *mergeSort = new MergeSort();
  mergeSort->sort(numbers, 9);
  for (int i = 0; i < 9; ++i)
  {
    std::cout << numbers[i] << " ";
  }
  return 0;
}
