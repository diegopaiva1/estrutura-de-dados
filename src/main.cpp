#include "data-structures/hash-table/HashTableCoalesced.hpp"

int main(int argc, char const *argv[])
{
  std::vector<int> data = {3, 18, 15, 92, 110, 12};

  HashTableCoalesced *hashTableCoalesced = new HashTableCoalesced(data, 0.75);

  hashTableCoalesced->insert(20);

  hashTableCoalesced->print();

  std::cout << std::endl;

  hashTableCoalesced->remove(92);

   hashTableCoalesced->print();

  return 0;
}
