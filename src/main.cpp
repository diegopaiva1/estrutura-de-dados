#include <iostream>
#include <time.h>
#include "data-structures/tree/patricia/PatriciaTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  PatriciaTree *patriciaTree = new PatriciaTree();

  patriciaTree->insert("ROMANE");
  patriciaTree->insert("ROMANUS");
  patriciaTree->insert("ROMULUS");
  patriciaTree->insert("RUBENS");
  patriciaTree->insert("RUBER");
  patriciaTree->insert("RUBICON");
  patriciaTree->insert("RUBICUNDUS");
  patriciaTree->insert("RUB");

  patriciaTree->printKeysByLevel();

  return 0;
}
