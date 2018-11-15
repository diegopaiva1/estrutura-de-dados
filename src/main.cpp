#include <iostream>
#include <time.h>
#include "components/deputy/file/reader/DeputyFileReader.hpp"
#include "components/TreePerformanceMeasurer.hpp"
#include "data-structures/tree/avl/AVLTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  AVLTree *avlTree = new AVLTree();

  avlTree->insert(9);
  avlTree->insert(120);
  avlTree->insert(13);
  avlTree->insert(45);
  avlTree->insert(155);
  avlTree->insert(1023);
  avlTree->insert(71);
  avlTree->insert(88);
  avlTree->insert(901);
  avlTree->insert(12);
  avlTree->insert(378);
  avlTree->insert(4);

  avlTree->printKeysByLevel();

  return 0;
}
