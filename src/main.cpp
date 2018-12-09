#include "components/HashTableComparisonsMeasurer.hpp"
#include "components/SortingAlgorithmPerformanceMeasurer.hpp"
#include "algorithms/sorting/HeapSort.hpp"
#include "algorithms/sorting/InsertionSort.hpp"
#include "algorithms/sorting/MergeSort.hpp"
#include "algorithms/sorting/SelectionSort.hpp"
#include "algorithms/sorting/QuickSort.hpp"
#include "data-structures/hash-table/HashTableSeparateChaining.hpp"
#include "data-structures/hash-table/HashTableOpenAddressing.hpp"
#include "data-structures/hash-table/HashTableCoalescedChaining.hpp"
#include "components/deputy/Deputy.hpp"
#include "components/deputy/DeputyHashTable.hpp"
#include "components/deputy/file/reader/DeputyFileReader.hpp"

#define MAX 1000

int main(int argc, char const *argv[])
{
  // Initialize random seed
  srand(time(NULL));



  // Arquivo passado por linha de comando
  std::string inFile = argv[1];

// // Vetor com os deputados da base de dados
  DeputyFileReader *deputyFileReader = new DeputyFileReader();

  std::vector<Deputy> deps = deputyFileReader->constructDeputies("dataset/teste.csv");
  DeputyHashTable *ht = new DeputyHashTable(deps, 0.75, "partido");

  ht->lowestsSpent(5);
  ht->highestsSpent(5);

  return 0;
}