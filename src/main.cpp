#include <iostream>
#include <string>
#include <vector>

#include "./Algoritmos/Ordenacao/SelectionSort.hpp"

int main(int argc, char const *argv[])
{
  int numbers[15] = {3, 44, 12, 125, 98, 765, 12, 155, 99, 258, 13, 50, 49, 80, 450};
  SelectionSort *selectionSort = new SelectionSort();
  selectionSort->sort(numbers, 15);
  for (int i = 0; i < 15; i++)
  {
    std::cout << sortedNames.at(i) << " ";
  }
  printf("\n");
  return 0;
}
