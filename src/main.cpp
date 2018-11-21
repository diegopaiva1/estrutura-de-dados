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

  PatriciaTree *patriciaTree = new PatriciaTree();

  // DeputyFileReader deputyFileReader;
  // std::vector<Deputy> deputies = deputyFileReader.constructDeputies("dataset/teste.csv");

  // for (auto deputy : deputies)
  //   patriciaTree->insert(deputy.receiptDescription);

  patriciaTree->insert("romane");
  patriciaTree->insert("romanes");
  patriciaTree->insert("romulus");
  patriciaTree->insert("rub");
  patriciaTree->insert("ruby");

  try
  {
    patriciaTree->printAutocompletionSuggestions("r");
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  return 0;
}
