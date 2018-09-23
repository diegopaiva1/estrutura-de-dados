#include "data-structures/HashTable.hpp"
#include <chrono>

typedef std::chrono::high_resolution_clock Time;

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  std::vector<int> data;

  for (int i = 0; i < 5000000; i++)
  {
    data.push_back(rand() % 5000000 + 1);
  }

  HashTable *hashTable = new HashTable(data, 0.75);

  Time::time_point t1 = Time::now();
  try
  {
    std::cout << hashTable->get(13528) << std::endl;
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
