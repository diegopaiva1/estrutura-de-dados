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
  patriciaTree->insert("RODOPIAR");
  patriciaTree->insert("RODOPIANDO");
  patriciaTree->insert("ABELHA");
  patriciaTree->insert("ABELHINHA");
  patriciaTree->insert("REI");

  patriciaTree->printKeysByLevel();

  return 0;
}
