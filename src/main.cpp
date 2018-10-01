#include "components/SortingAlgorithmPerformanceMeasurer.hpp"
#include "algorithms/sorting/HeapSort.hpp"
#include "data-structures/hash-table/HashTableCoalescedChaining.hpp"

int main(int argc, char const *argv[])
{
  std::string fileName = argv[1];

  std::vector<int> data = {10, 20, 30, 40, 60, 110, 218, 191};

  HashTableCoalescedChaining *t = new HashTableCoalescedChaining(data, 0.75);

  // SortingAlgorithmPerformanceMeasurer *measurer = new SortingAlgorithmPerformanceMeasurer();
  // measurer->storePerformanceResults(fileName, new HeapSort());

  return 0;
}
