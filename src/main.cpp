#include <iostream>
#include <string>
#include <vector>

#include "./Algoritmos/Ordenacao/InsertionSort.hpp"

int main(int argc, char const *argv[])
{
  std::vector<int> v = {564, 15615, 132, 165, 22, 66, 89, 156, 33, 165, 99};
  InsertionSort *insertionSort = new InsertionSort();
  insertionSort->sort(v);
  for (unsigned int i = 0; i < v.size(); i++)
  {
    std::cout << v.at(i) << " ";
  }
  printf("\n");
  return 0;
}
