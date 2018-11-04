#include <iostream>
#include <time.h>
#include "data-structures/tree/b/BTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  BTree *b = new BTree(5);

  b->root = b->insert(5);
  b->insert(71);
  b->insert(9);
  b->insert(18);

  std::cout << b->root->hasOverflow() << '\n';
  std::cout << b->root->keys.size() << '\n';

  return 0;
}
