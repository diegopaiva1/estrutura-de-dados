#include "algorithms/sorting/HeapSort.hpp"

int main(int argc, char const *argv[])
{
  std::vector<int> numbers = {2, 8, 5, 3, 9 , 1};
  HeapSort *heapSort = new HeapSort();
  heapSort->sort(numbers);
  for(auto i : numbers)
  {
    std::cout << i << " ";
  }
  printf("\n");
  return 0;
}
