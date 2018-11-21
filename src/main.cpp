#include <iostream>
#include <time.h>
#include "data-structures/tree/patricia/PatriciaTree.hpp"
#include "components/deputy/file/reader/DeputyFileReader.hpp"
#include "components/deputy/Deputy.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  PatriciaTree *patriciaTree = new PatriciaTree();

  DeputyFileReader deputyFileReader;
  std::vector<Deputy> deputies = deputyFileReader.constructDeputies("dataset/teste.csv");

  for (auto deputy : deputies)
  {
    auto gastos = deputyFileReader.explode(deputy.receiptDescription, ' ');

    for (auto gasto : gastos)
      patriciaTree->insert(gasto);
  }

  // patriciaTree->insert("romane");
  // patriciaTree->insert("romanes");
  // patriciaTree->insert("romulus");
  // patriciaTree->insert("rub");
  // patriciaTree->insert("ruby");

  try
  {
    patriciaTree->printAutocompletionSuggestions("tel");
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  //patriciaTree->printKeysByLevel();

  return 0;
}
