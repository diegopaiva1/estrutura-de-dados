#include <iostream>
#include <time.h>
#include "data-structures/tree/patricia/PatriciaTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  PatriciaTree *patriciaTree = new PatriciaTree();

  patriciaTree->insert("RODOVIA");
  patriciaTree->insert("RODOVIARIO");
  patriciaTree->insert("RODOVIARIA");
  patriciaTree->insert("RODOANEL");
  // patriciaTree->insert("ABELHA");

  std::cout << patriciaTree->root->word << '\n';
  std::cout << patriciaTree->root->children.at(0)->word << '\n';
  std::cout << patriciaTree->root->children.at(21)->word << '\n';
  std::cout << patriciaTree->root->children.at(21)->children.at(17)->word << '\n';

  return 0;
}
