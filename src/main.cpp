#include <iostream>
#include <time.h>
#include "data-structures/tree/b/BTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  BTree *b = new BTree(5);

  b->insert(10);
  b->insert(100);
  b->insert(13);
  b->insert(74);
  b->insert(128);
  b->insert(256);
  b->insert(512);
  b->insert(65);
  b->insert(19);
  b->insert(1024);
  b->insert(113);
  b->insert(118);
  b->insert(250);

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
  printf("\n");
  for (auto key : b->root->children.at(2)->keys)
  {
    std::cout << key << '\n';
  }
  printf("\n");
  // for (auto child : b->root->children)
  // {
  //   for (auto key : child->keys)
  //   {
  //     std::cout << key << '\n';
  //   }
  // }

  return 0;
}
