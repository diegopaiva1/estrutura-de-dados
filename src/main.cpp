#include <iostream>

#include "./Algoritmos/Ordenacao/MergeSort/MergeSort.h"

int main(int argc, char const *argv[])
{
  int sortedList1[3] = {8, 12, 90};
  int sortedList2[3] = {7, 29, 53};
  int mergedList[6];
  MergeSort *mergeSort = new MergeSort();
  mergeSort->mergeTwoSortedLists(sortedList1, 3, sortedList2, 3, mergedList);
  for (int i = 0; i < 6; i++)
  {
    std::cout << mergedList[i] << " ";
  }
  printf("\n");
  return 0;
}
