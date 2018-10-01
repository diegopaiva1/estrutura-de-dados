#include "components/SortingAlgorithmPerformanceMeasurer.hpp"
#include "algorithms/sorting/HeapSort.hpp"

int main(int argc, char const *argv[])
{
  std::string fileName = argv[1];

  SortingAlgorithmPerformanceMeasurer *measurer = new SortingAlgorithmPerformanceMeasurer();
  measurer->storePerformanceResults(fileName, new HeapSort());

  return 0;
}
