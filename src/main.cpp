#include <iostream>
#include <time.h>
#include "data-structures/tree/red-black/RedBlackTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  RedBlackTree *redBlackTree = new RedBlackTree();

  // redBlackTree->insert(30);
  // redBlackTree->insert(20);
  // redBlackTree->insert(40);
  // redBlackTree->insert(10);

  // redBlackTree->remove(20);

  redBlackTree->insert(30);
  redBlackTree->insert(20);
  redBlackTree->insert(40);
  redBlackTree->insert(35);
  // redBlackTree->insert(39);
  // redBlackTree->insert(188);
  // redBlackTree->insert(200);
  // redBlackTree->insert(27);
  // redBlackTree->insert(58);

  redBlackTree->remove(20);

  redBlackTree->printKeysByLevel();

  std::cout << redBlackTree->root->key << '\n';
  std::cout << redBlackTree->root->left->key << '\n';
  std::cout << redBlackTree->root->right->key << '\n';

  return 0;
}
