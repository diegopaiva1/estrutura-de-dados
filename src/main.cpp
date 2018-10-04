#include "components/HashTableComparisonsMeasurer.hpp"
#include "data-structures/hash-table/HashTableCoalescedChaining.hpp"

int main(int argc, char const *argv[])
{
  // Arquivo passado por linha de comando
  std::string inFile = argv[1];

  HashTableComparisonsMeasurer *measurer = new HashTableComparisonsMeasurer();
  measurer->storeComparisonsResults(inFile, new HashTableCoalescedChaining());

  return 0;
}
