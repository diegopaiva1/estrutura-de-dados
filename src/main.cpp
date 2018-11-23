#include <iostream>
#include <time.h>
#include "data-structures/tree/avl/AVLTree.hpp"
#include "components/TreePerformanceMeasurer.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  TreePerformanceMeasurer tpm;

  tpm.storePerformanceResults("dataset/entrada.txt", new AVLTree(), "saidaInsercao.txt");

  return 0;
}
