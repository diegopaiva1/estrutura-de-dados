#include "components/SortingAlgorithmPerformanceMeasurer.hpp"
#include "algorithms/sorting/SelectionSort.hpp"

int main(int argc, char const *argv[])
{
  std::string fileName = argv[1];

  SortingAlgorithmPerformanceMeasurer *measurer = new SortingAlgorithmPerformanceMeasurer();
  measurer->storePerformanceResults(fileName, new SelectionSort());

  return 0;
}
