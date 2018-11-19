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

  try
  {
    std::cout << patriciaTree->hasWord("ROMANE") << '\n';
    std::cout << patriciaTree->hasWord("ROMANUS") << '\n';
    std::cout << patriciaTree->hasWord("ROMULUS") << '\n';
    std::cout << patriciaTree->hasWord("RUBENS") << '\n';
    std::cout << patriciaTree->hasWord("RUBER") << '\n';
    std::cout << patriciaTree->hasWord("RUBICON") << '\n';
    std::cout << patriciaTree->hasWord("RUBICUNDUS") << '\n';
    std::cout << patriciaTree->hasWord("RUBY") << '\n';
  }
  catch (char const* exception)
  {
    std::cerr << exception << std::endl;
  }

  patriciaTree->printKeysByLevel();

  return 0;
}
