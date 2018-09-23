#include "data-structures/hash-table/HashTableSeparateChaining.hpp"
#include <chrono>

typedef std::chrono::high_resolution_clock Time;

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  std::vector<int> data = {10, 20, 30, 60, 80};

  HashTableSeparateChaining *hashTable = new HashTableSeparateChaining(data, 0.75);

  Time::time_point t1 = Time::now();
  try
  {
    hashTable->remove(9);
  }
  catch (const char* error)
  {
    std::cerr << error << '\n';
  }
  Time::time_point t2 = Time::now();

  double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

  std::cout << "Tempo total de busca: " << duration/1000000000 << "s" << std::endl;

  return 0;
}
