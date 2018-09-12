#include "algorithms/sorting/HeapSort.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  std::vector<int> numbers;

  for(int i = 0; i < 15000; i++)
  {
    numbers.push_back(rand() % 15000 + 1);
  }

  HeapSort *heapSort = new HeapSort();
  heapSort->sort(numbers);

  for(auto i : numbers)
  {
    std::cout << i << std::endl;
  }
  printf("\n");
  return 0;
}
