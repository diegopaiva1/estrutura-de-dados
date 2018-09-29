#include "data-structures/hash-table/HashTableSeparateChaining.hpp"

int main(int argc, char const *argv[])
{
  std::vector<int> data = {10, 293, 219, 21, 38, 19, 155, 12, 94, 38, 70};

  HashTableSeparateChaining *hashTable = new HashTableSeparateChaining(data, 0.75);

  try
  {
    hashTable->get(70);
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  return 0;
}
