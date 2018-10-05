#include "components/HashTableComparisonsMeasurer.hpp"
#include "algorithms/sorting/QuickSort.hpp"
#include "data-structures/hash-table/HashTableOpenAddressing.hpp"

int main(int argc, char const *argv[])
{
  // Arquivo passado por linha de comando
  std::string inFile = argv[1];

  HashTableComparisonsMeasurer *measurer = new HashTableComparisonsMeasurer();
  measurer->storeComparisonsResults(inFile, new HashTableOpenAddressing("Linear Probing"));

  return 0;
}
