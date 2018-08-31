#include "data-structures/HashTable.hpp"

int main(int argc, char const *argv[])
{
  std::vector<int> data = {165, 112, 134, 48, 988, 165, 644, 6456, 121, 65, 899, 155, 12};

  HashTable *hashTable = new HashTable(data, 0.75);

  std::cout << hashTable->get(134) << std::endl;

  return 0;
}
