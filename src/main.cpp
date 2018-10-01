#include "components/SortingAlgorithmPerformanceMeasurer.hpp"
#include "algorithms/sorting/InsertionSort.hpp"

#include <iomanip>

int main(int argc, char const *argv[])
{
  std::string fileName = argv[1];

  SortingAlgorithmPerformanceMeasurer *measurer = new SortingAlgorithmPerformanceMeasurer();
  measurer->storePerformanceResults(fileName, new InsertionSort());

  return 0;
}
