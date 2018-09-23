#include "components/SortingAlgorithmTimeMeasurer.hpp"
#include "algorithms/sorting/MergeSort.hpp"
#include "algorithms/sorting/HeapSort.hpp"
#include "algorithms/sorting/QuickSort.hpp"

int main(int argc, char const *argv[])
{
  std::string fileName = argv[1];

  SortingAlgorithmTimeMeasurer *measurer = new SortingAlgorithmTimeMeasurer();

  measurer->storeExecutionTimeResults(fileName, new MergeSort());
  measurer->storeExecutionTimeResults(fileName, new HeapSort());
  measurer->storeExecutionTimeResults(fileName, new QuickSort());

  return 0;
}
