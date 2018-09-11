#include "components/file/reader/DeputyFileReader.hpp"
#include "components/deputy/Deputy.hpp"
#include "algorithms/sorting/InsertionSort.hpp"

int main(int argc, char const *argv[])
{
  // Arquivo passado por linha de comando
  std::string fileName = argv[1];

  DeputyFileReader *deputyFileReader = new DeputyFileReader();

  std::vector<Deputy> deputies = deputyFileReader->constructDeputies(fileName);

  InsertionSort *mergeSort = new InsertionSort();
  mergeSort->sort(deputies);

  for (auto deputy : deputies)
  {
    std::cout << "Nome: "                    << deputy.name              << std::endl;
    std::cout << "Partido: "                 << deputy.party             << std::endl;
    std::cout << "Nome do estabelecimento: " << deputy.establishmentName << std::endl;
    std::cout << "Valor do recibo: "         << deputy.receiptValue      << std::endl;
    printf("\n");
  }

  return 0;
}
