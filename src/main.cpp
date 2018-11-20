#include <iostream>
#include <time.h>
#include "data-structures/tree/patricia/PatriciaTree.hpp"
#include "components/deputy/file/reader/DeputyFileReader.hpp"
#include "components/deputy/Deputy.hpp"

std::vector<std::string> explode(std::string const & string, char delimiter)
{
  std::vector<std::string> result;
  std::istringstream iss(string);

  for (std::string token; std::getline(iss, token, delimiter); )
    result.push_back(std::move(token));

  return result;
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  DeputyFileReader deputyFileReader;
  std::vector<Deputy> deputies = deputyFileReader.constructDeputies("dataset/teste.csv");

  PatriciaTree *patriciaTree = new PatriciaTree();

  patriciaTree->insert("romane");
  patriciaTree->insert("romanus");
  patriciaTree->insert("romulus");
  patriciaTree->insert("rubens");
  patriciaTree->insert("ruber");
  patriciaTree->insert("rubicon");
  patriciaTree->insert("rubicundus");
  patriciaTree->insert("ruby");
  patriciaTree->insert("rubious");
  patriciaTree->insert("roman");
  patriciaTree->insert("rub");

  std::cout << patriciaTree->hasWord("romane") << '\n';
  std::cout << patriciaTree->hasWord("romanus") << '\n';
  std::cout << patriciaTree->hasWord("romulus") << '\n';
  std::cout << patriciaTree->hasWord("rubens") << '\n';
  std::cout << patriciaTree->hasWord("ruber") << '\n';
  std::cout << patriciaTree->hasWord("rubicon") << '\n';
  std::cout << patriciaTree->hasWord("rubicundus") << '\n';
  std::cout << patriciaTree->hasWord("ruby") << '\n';
  std::cout << patriciaTree->hasWord("rubious") << '\n';
  std::cout << patriciaTree->hasWord("roman") << '\n';
  std::cout << patriciaTree->hasWord("rub") << '\n';

  patriciaTree->printKeysByLevel();

  return 0;
}
