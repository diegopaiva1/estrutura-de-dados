#include <iostream>
#include <string>
#include <vector>

#include "./Algorithms/Sorting/MergeSort.hpp"

int main(int argc, char const *argv[])
{
  std::vector<float> v = {73.60301, 90.10401, 90.20021, 3.14159, 89.6875, 89.6857};
  MergeSort *mergeSort = new MergeSort();
  mergeSort->sort(v);
  for (unsigned int i = 0; i < v.size(); i++)
  {
    std::cout << v.at(i) << " ";
  }
  printf("\n");
  return 0;
}
