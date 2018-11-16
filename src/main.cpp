#include <iostream>
#include <time.h>
#include "data-structures/tree/red-black/RedBlackTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  RedBlackTree *redBlackTree = new RedBlackTree();

  redBlackTree->insert(30);
  redBlackTree->insert(20);
  redBlackTree->insert(40);
  redBlackTree->insert(10);

  // redBlackTree->remove(20);

  redBlackTree->printKeysByLevel();

  return 0;
}
