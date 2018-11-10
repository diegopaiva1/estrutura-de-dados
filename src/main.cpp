#include <iostream>
#include <time.h>
#include "data-structures/tree/b/BTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  BTree *b = new BTree(3);

  b->insert(2);
  b->insert(20);
  b->insert(21);
  b->insert(1);
  b->insert(3);
  b->insert(49);
  b->insert(52);

  for (auto key : b->root->keys)
  {
    std::cout << key << '\n';
  }
  printf("\n");
  for (auto key : b->root->children.at(0)->keys)
  {
    std::cout << key << '\n';
  }
  printf("\n");
  for (auto key : b->root->children.at(1)->keys)
  {
    std::cout << key << '\n';
  }

  return 0;
}
