#include "components/SortingAlgorithmTimeMeasurer.hpp"
#include "algorithms/sorting/MergeSort.hpp"
#include "algorithms/sorting/HeapSort.hpp"

int main(int argc, char const *argv[])
{
  // Arquivo passado por linha de comando
  std::string fileName = argv[1];

  SortingAlgorithmTimeMeasurer *timeMeasurer = new SortingAlgorithmTimeMeasurer();

  timeMeasurer->printResults(fileName, new MergeSort());
  timeMeasurer->printResults(fileName, new HeapSort());

  return 0;
}
