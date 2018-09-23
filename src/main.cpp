#include "data-structures/HashTableQuadraticProbing.hpp"
#include "data-structures/HashTableLinearProbing.hpp"
#include "data-structures/HashTableDoubleHashing.hpp"

int main(int argc, char const *argv[])
{
  std::vector<int> data = {0,0,10,3,4};

  HashTableQuadraticProbing *hashTableQuadraticProbing = new HashTableQuadraticProbing(data, 0.75);
  HashTableLinearProbing *hashTableLinearProbing = new HashTableLinearProbing(data, 0.75);
  HashTableDoubleHashing *hashTableDoubleHashing = new HashTableDoubleHashing(data, 0.75);

  hashTableQuadraticProbing->imprimir();
  hashTableLinearProbing->imprimir();
  hashTableDoubleHashing->imprimir();

  hashTableQuadraticProbing->remove(165);
  hashTableLinearProbing->remove(165);
  hashTableDoubleHashing->remove(165);

  hashTableQuadraticProbing->imprimir();
  hashTableLinearProbing->imprimir();
  hashTableDoubleHashing->imprimir();

  try
  {
    std::cout << hashTableQuadraticProbing->get(165) << std::endl;
  }
  catch (const char* error)
  {
    std::cerr << error << '\n';
  }

  try
  {
    std::cout << hashTableLinearProbing->get(165) << std::endl;
  }
  catch (const char* error)
  {
    std::cerr << error << '\n';
  }

  try
  {
    std::cout << hashTableDoubleHashing->get(165) << std::endl;
  }
  catch (const char* error)
  {
    std::cerr << error << '\n';
  }

  return 0;
}
