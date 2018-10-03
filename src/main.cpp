#include "components/SortingAlgorithmPerformanceMeasurer.hpp"
#include "algorithms/sorting/HeapSort.hpp"
#include "algorithms/sorting/MergeSort.hpp"
#include "algorithms/sorting/InsertionSort.hpp"
#include "algorithms/sorting/SelectionSort.hpp"

int main(int argc, char const *argv[])
{
  // Arquivo passado por linha de comando
  std::string inFile = argv[1];

  SortingAlgorithmPerformanceMeasurer *measurer = new SortingAlgorithmPerformanceMeasurer();
  measurer->storePerformanceResults(inFile, new HeapSort());
  measurer->storePerformanceResults(inFile, new MergeSort());
  measurer->storePerformanceResults(inFile, new InsertionSort());
  measurer->storePerformanceResults(inFile, new SelectionSort());

  return 0;
}
