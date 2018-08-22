#include <iostream>
#include <vector>

#include "./Algoritmos/Ordenacao/MergeSort/MergeSort.h"

int main(int argc, char const *argv[])
{
  std::vector<int> numbers = {30, 4, 5, 92, 18, 73, 22};
  MergeSort *mergeSort = new MergeSort();
  auto sortedNumbers = mergeSort->sort(numbers);
  for (unsigned int i = 0; i < sortedNumbers.size(); ++i)
  {
    std::cout << sortedNumbers.at(i) << " ";
  }
  return 0;
}
