#include <iostream>
#include <time.h>
#include "data-structures/tree/patricia/PatriciaTree.hpp"
#include "components/deputy/file/reader/DeputyFileReader.hpp"
#include "components/deputy/Deputy.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  DeputyFileReader deputyFileReader;
  std::vector<Deputy> deputies = deputyFileReader.constructDeputies("dataset/teste.csv");

  for (auto deputy : deputies)
    std::cout << deputy.receiptDescription << '\n';

  PatriciaTree *patriciaTree = new PatriciaTree();

  patriciaTree->insert("ROMANE");
  patriciaTree->insert("ROMANUS");
  patriciaTree->insert("ROMULUS");
  patriciaTree->insert("RUBENS");
  patriciaTree->insert("RUBER");
  patriciaTree->insert("RUBICON");
  patriciaTree->insert("RUBICUNDUS");
  patriciaTree->insert("RUB");
  patriciaTree->insert("RUBY");

  // std::cout << patriciaTree->hasWord("ROMANE") << '\n';
  // std::cout << patriciaTree->hasWord("ROMANUS") << '\n';
  // std::cout << patriciaTree->hasWord("ROMULUS") << '\n';
  // std::cout << patriciaTree->hasWord("RUBENS") << '\n';
  // std::cout << patriciaTree->hasWord("RUBER") << '\n';
  // std::cout << patriciaTree->hasWord("RUBICON") << '\n';
  // std::cout << patriciaTree->hasWord("RUBICUNDUS") << '\n';
  // std::cout << patriciaTree->hasWord("RUBY") << '\n';
  // std::cout << patriciaTree->hasWord("RUBIOUS") << '\n';
  // std::cout << patriciaTree->hasWord("ROMAN") << '\n';

  patriciaTree->printKeysByLevel();

  return 0;
}
