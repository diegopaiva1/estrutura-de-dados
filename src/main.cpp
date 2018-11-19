#include <iostream>
#include <time.h>
#include "data-structures/tree/patricia/PatriciaTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  PatriciaTree *patriciaTree = new PatriciaTree();

  patriciaTree->insert("MACA");
  patriciaTree->insert("MACACO");
  patriciaTree->insert("MACAQUINHO");
  patriciaTree->insert("MACAQUICE");
  // patriciaTree->insert("INSETICIDA");

  std::cout << patriciaTree->root->word << '\n';
  std::cout << patriciaTree->root->children.at(2)->word << '\n';
  std::cout << patriciaTree->root->children.at(16)->word << '\n';

  return 0;
}
