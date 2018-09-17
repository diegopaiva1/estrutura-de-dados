#include "components/SortingAlgorithmTimeMeasurer.hpp"
#include "algorithms/sorting/MergeSort.hpp"

int main(int argc, char const *argv[])
{
  // Arquivo passado por linha de comando
  std::string fileName = argv[1];

  SortingAlgorithmTimeMeasurer *timeMeasurer = new SortingAlgorithmTimeMeasurer();

  timeMeasurer->printResults(fileName, new MergeSort());

  return 0;
}
