#include <iostream>
#include <time.h>
#include "data-structures/tree/red-black/RedBlackTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  RedBlackTree *redBlackTree = new RedBlackTree();

  redBlackTree->insert(10);
  redBlackTree->insert(6);

  std::cout << redBlackTree->root->key << '\n';
  redBlackTree->root->color == RED ? std::cout << "Red" << '\n'
                                   : std::cout << "Black" << '\n';

  std::cout << redBlackTree->root->left->key << '\n';
  redBlackTree->root->left->color == RED ? std::cout << "Red" << '\n'
                                         : std::cout << "Black" << '\n';

  std::cout << redBlackTree->root->right->key << '\n';
  redBlackTree->root->right->color == RED ? std::cout << "Red" << '\n'
                                          : std::cout << "Black" << '\n';

  // std::cout << redBlackTree->root->right->right->key << '\n';
  // redBlackTree->root->right->right->color == RED ? std::cout << "Red" << '\n'
  //                                         : std::cout << "Black" << '\n';

  return 0;
}
