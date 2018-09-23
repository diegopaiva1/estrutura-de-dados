#include "data-structures/hash-table/HashTableOpenAddressing.hpp"

int main(int argc, char const *argv[])
{
  std::vector<int> data = {1, 2, 10, 3, 4, 687, 93, 11};

  HashTableOpenAddressing *hashTableOpenAddressing = new HashTableOpenAddressing(10, "Linear Probing");

  hashTableOpenAddressing->insert(3);

  return 0;
}
