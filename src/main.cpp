#include <iostream>
#include <string>
#include <vector>

#include "./Algoritmos/Ordenacao/SelectionSort.hpp"

int main(int argc, char const *argv[])
{
  std::vector<int> v = {3, 44, 12, 125, 98, 765, 12, 155, 99, 258, 13, 50, 49, 80, 450};
  SelectionSort *selectionSort = new SelectionSort();
  selectionSort->sort(v);
  for (unsigned int i = 0; i < v.size(); i++)
  {
    std::cout << v.at(i) << " ";
  }
  printf("\n");
  return 0;
}


