#include <iostream>

#include "./Algoritmos/Ordenacao/MergeSort/MergeSort.h"

int main(int argc, char const *argv[])
{
  int sortedList1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int sortedList2[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int mergedList[20];
  MergeSort *mergeSort = new MergeSort();
  mergeSort->mergeTwoSortedLists(sortedList1, 10, sortedList2, 10, mergedList);
  for (int i = 0; i < 20; i++)
  {
    std::cout << mergedList[i] << " ";
  }
  printf("\n");
  return 0;
}
