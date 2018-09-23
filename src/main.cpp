#include "data-structures/HashTableQuadraticProbing.hpp"
#include "data-structures/HashTableLinearProbing.hpp"
#include "data-structures/HashTableDoubleHashing.hpp"

int main(int argc, char const *argv[])
{
  std::vector<int> data = {1, 2, 10, 3, 4, 687, 93, 11};

  //HashTableQuadraticProbing *hashTableQuadraticProbing = new HashTableQuadraticProbing(data, 0.75);
  HashTableOpenAddressing *hashTableOpenAddressing = new HashTableOpenAddressing(10, "Linear Probing");
  //HashTableDoubleHashing *hashTableDoubleHashing = new HashTableDoubleHashing(data, 0.75);

  hashTableOpenAddressing->insert(3);

  //hashTableQuadraticProbing->imprimir();
  //hashTableLinearProbing->imprimir();
  //hashTableDoubleHashing->imprimir();

  //hashTableQuadraticProbing->remove(3);
  //hashTableLinearProbing->remove(3);
  //hashTableDoubleHashing->remove(3);

  //hashTableQuadraticProbing->imprimir();
  //hashTableLinearProbing->imprimir();
  //hashTableDoubleHashing->imprimir();

  return 0;
}
