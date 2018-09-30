#include "components/SortingAlgorithmTimeMeasurer.hpp"
#include "algorithms/sorting/MergeSort.hpp"
#include "algorithms/sorting/HeapSort.hpp"

int main(int argc, char const *argv[])
{
  //srand(time(NULL));
  //int a=rand() % 1 + 1000;

  // Arquivo passado por linha de comando
  std::string fileName = argv[1];

  SortingAlgorithmTimeMeasurer *timeMeasurer = new SortingAlgorithmTimeMeasurer();

  timeMeasurer->storeExecutionTimeResults(fileName, new MergeSort());
  timeMeasurer->storeExecutionTimeResults(fileName, new HeapSort());

  return 0;
}
