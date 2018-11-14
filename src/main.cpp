#include <iostream>
#include <time.h>
#include "components/deputy/file/reader/DeputyFileReader.hpp"
#include "components/TreePerformanceMeasurer.hpp"
#include "data-structures/tree/avl/AVLTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  TreePerformanceMeasurer tpm;

  AVLTree *avlTree = new AVLTree();

  tpm.storePerformanceResults("dataset/entrada.txt", avlTree, "saidaInsercao.txt");


  return 0;
}
