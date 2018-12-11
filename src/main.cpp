#include <iostream>
#include <time.h>
#include "data-structures/tree/red-black/RedBlackTree.hpp"
#include "data-structures/tree/avl/AVLTree.hpp"
#include "data-structures/tree/b/BTree.hpp"
#include "data-structures/tree/splay/SplayTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  BTree *bTree = new BTree(3);

  bTree->insert(9);
  bTree->insert(120);
  bTree->insert(13);
  bTree->insert(45);
  bTree->insert(155);
  bTree->insert(1023);
  bTree->insert(71);
  bTree->insert(88);
  bTree->insert(901);
  bTree->insert(12);
  bTree->insert(378);
  bTree->insert(4);

  for (auto key : bTree->root->keys)
    std::cout << key << std::endl;

  for (auto child : bTree->root->children)
    if (child != nullptr)
      for (auto key : child->keys)
        std::cout << key << std::endl;

  std::cout << std::endl;

  try
  {
     bTree->remove(120);
  }
  catch (const char* exception)
  {
    std::cerr << exception << '\n';
  }

  for (auto key : bTree->root->keys)
    std::cout << key << std::endl;

  for (auto child : bTree->root->children)
    if (child != nullptr)
      for (auto key : child->keys)
        std::cout << key << std::endl;

  return 0;
}
