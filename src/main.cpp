#include <iostream>

#include "./Algoritmos/Ordenacao/InsertionSort/InsertionSort.h"

int main(int argc, char const *argv[])
{
  int numbers[15] = {15, 20, 98, 1, 50, 66, 25, 2059, 10580, 505, 1120, 505, 134, 988, 650};
  InsertionSort *insertionSort = new InsertionSort();
  insertionSort->sort(numbers, 15);
  for (int i = 0; i < 15; i++)
  {
    std::cout << numbers[i] << " ";
  }
  printf("\n");
  return 0;
}
