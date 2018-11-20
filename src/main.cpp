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

  for (auto deputy : deputies)
    patriciaTree->insert(deputy.receiptDescription);

  // patriciaTree->insert("romane");
  // patriciaTree->insert("romanus");
  // patriciaTree->insert("romulus");
  // patriciaTree->insert("rubens");
  // patriciaTree->insert("ruber");
  // patriciaTree->insert("rubicon");
  // patriciaTree->insert("rubicundus");
  // patriciaTree->insert("ruby");
  // patriciaTree->insert("rubious");
  // patriciaTree->insert("roman");
  // patriciaTree->insert("rub");

  try
  {
    for (auto word : patriciaTree->getSuggestedWords("rom"))
      std::cout << word << '\n';
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  patriciaTree->printKeysByLevel();

  return 0;
}
