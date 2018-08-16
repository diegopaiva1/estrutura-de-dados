#include <iostream>

#include "./Algoritmos/Ordenacao/MergeSort/MergeSort.h"

int main(int argc, char const *argv[])
{
  int numbers[16] = {56, 20, 9, 98, 45, 65, 7, 89, 102, 66, 124, 56, 1, 14, 16, 15};
  int sortedList[16];
  MergeSort *mergeSort = new MergeSort();
  mergeSort->sort(numbers, 16, sortedList);
  for (int i = 0; i < 16; ++i)
  {
    std::cout << sortedList[i] << " ";
  }



  return 0;
}
