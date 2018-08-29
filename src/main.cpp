#include "components/file/reader/DeputyFileReader.hpp"
#include "components/deputy/Deputy.hpp"
#include "algorithms/sorting/MergeSort.hpp"
#include "data-structures/HashTable.hpp"

int main(int argc, char const *argv[])
{
  std::vector<int> data = {44, 67, 49, 46, 68, 71, 97};

  HashTable *hashTable = new HashTable(data);

  auto items = hashTable->data.at(hashTable->hashIt(44));

  for (auto i = items.begin(); i != items.end(); i++)
  {
    std::cout << *i << std::endl;
  }

  // // Arquivo passado por linha de comando
  // std::string fileName = argv[1];

  // DeputyFileReader *deputyFileReader = new DeputyFileReader();

  // std::vector<Deputy> deputies = deputyFileReader->constructDeputies(fileName);

  // MergeSort *mergeSort = new MergeSort();
  // mergeSort->sort(deputies);

  // for (int i = 0; i < deputies.size(); i++)
  // {
  //   std::cout << "Nome: " << deputies.at(i).name << std::endl;
  //   std::cout << "Partido: " << deputies.at(i).party << std::endl;
  //   std::cout << "Nome do estabelecimento: " << deputies.at(i).establishmentName << std::endl;
  //   std::cout << "Valor do recibo: " << deputies.at(i).receiptValue << std::endl;
  //   printf("\n");
  // }

  return 0;
}
