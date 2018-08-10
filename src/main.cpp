#include <iostream>

#include "./Algoritmos/Ordenacao/InsertionSort/InsertionSort.h"

int main(int argc, char const *argv[])
{
  int numbers[6] = {123, 984, 155, 30, 20, 200};
  InsertionSort *insertionSort = new InsertionSort();
  insertionSort->sort(numbers, 6);
  for (int i = 0; i < 6; i++)
  {
    std::cout << numbers[i] << " ";
  }
  printf("\n");
  return 0;
}
