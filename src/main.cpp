#include "components/SortingAlgorithmPerformanceMeasurer.hpp"
#include "algorithms/sorting/InsertionSort.hpp"

#include <iomanip>

int main(int argc, char const *argv[])
{
  std::string fileName = argv[1];

  std::vector<int> numbers;

  for (int i = 0; i < 500000; i++)
  {
    numbers.push_back(rand() % 500000 + 1);
  }

  InsertionSort *insertionSort = new InsertionSort();
  insertionSort->sort(numbers);

  for (auto n : numbers)
  {
    std::cout << n << std::endl;
  }

  std::cout << "Tempo de execução = " << std::setprecision(4) << insertionSort->executionTime << "s" << std::endl;
  std::cout << "Comparações = " << insertionSort->comparisons << std::endl;
  std::cout << "Cópias = " << insertionSort->copies << std::endl;

  // SortingAlgorithmPerformanceMeasurer *measurer = new SortingAlgorithmPerformanceMeasurer();
  // measurer->storePerformanceResults(fileName, new InsertionSort());

  return 0;
}
