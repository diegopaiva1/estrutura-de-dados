#include <iostream>
#include <time.h>
#include "data-structures/tree/b/BTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  BTree *b = new BTree(5);

  b->insert(5);
  b->insert(71);
  b->insert(9);
  b->insert(18);
  b->insert(4);

  for (auto key : b->root->keys)
  {
    std::cout << key << '\n';
  }

  return 0;
}
