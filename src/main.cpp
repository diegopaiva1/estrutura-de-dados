#include "Components/File/Reader/DeputyFileReader.hpp"
#include "Components/Deputy/Deputy.hpp"
#include "Algorithms/Sorting/InsertionSort.hpp"

int main(int argc, char const *argv[])
{
  // Arquivo passado por linha de comando
  std::string fileName = argv[1];

  DeputyFileReader *deputyFileReader = new DeputyFileReader();

  std::vector<Deputy> deputies = deputyFileReader->constructDeputies(fileName);

  InsertionSort *insertionSort = new InsertionSort();
  insertionSort->sort(deputies);

  for (deputy : deputies)
  {
    std::cout << "Nome: " << deputy.name << std::endl;
    std::cout << "Partido: " << deputy.party << std::endl;
    std::cout << "Nome do estabelecimento: " << deputy.establishmentName << std::endl;
    std::cout << "Valor do recibo: " << deputy.receiptValue << std::endl;
    printf("\n");
  }

  return 0;
}
