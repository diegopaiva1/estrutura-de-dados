#include <iostream>
#include <time.h>
#include "data-structures/tree/red-black/RedBlackTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  RedBlackTree *redBlackTree = new RedBlackTree();

  redBlackTree->insert(10);
  redBlackTree->insert(9);
  redBlackTree->insert(8);
  redBlackTree->insert(7);
  redBlackTree->insert(6);
  redBlackTree->insert(5);
  redBlackTree->insert(4);
  redBlackTree->insert(3);
  redBlackTree->insert(2);
  redBlackTree->insert(1);

  std::cout << "Raíz = " << redBlackTree->root->key << '\n';

  redBlackTree->printKeysByLevel();

  return 0;
}
