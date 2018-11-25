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

  // patriciaTree->insert("PORTA");
  // patriciaTree->insert("PORTAL");
  // patriciaTree->insert("PORTAIS");
  // patriciaTree->insert("PORTELA");
  // patriciaTree->insert("PERCEVEJO");
  // patriciaTree->insert("PERGUNTA");
  // patriciaTree->insert("AMEIXA");
  // patriciaTree->insert("AMAR");
  // patriciaTree->insert("PORCELANA");
  // patriciaTree->insert("PIMENTA");
  // patriciaTree->insert("ABACATE");
  // patriciaTree->insert("INSETO");
  // patriciaTree->insert("INSETICIDA");

  try
  {
    patriciaTree->printAutocompletionSuggestions("T");
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  return 0;
}
