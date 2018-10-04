#include "components/file/reader/DeputyFileReader.hpp"
#include "components/deputy/Deputy.hpp"
#include "algorithms/sorting/InsertionSort.hpp"
#include "algorithms/sorting/QuickSort.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  // Arquivo passado por linha de comando
  std::string fileName = argv[1];

  DeputyFileReader *deputyFileReader = new DeputyFileReader();
  std::vector<Deputy> deputies = deputyFileReader->constructDeputies(fileName);

  //std::vector<int> teste = {6, 8, 2, 32, 14, 70, 61, 55, 47, 150, 130, 111, 170, 134, 122, 200};

  QuickSort *quickSort = new QuickSort();

  //quickSort->sort(deputies); //Quick
  quickSort->sort(deputies, 4); //QuickMediana
  //quickSort->sort(deputies, 0, 4); //QuickInsertion
  //quickSort->sort(deputies, 4, 4); //QuickMedianaInsertion

  //quickSort->sort(teste, 4, 4);

  for (auto deputy : deputies)
  {
    //std::cout << "Nome: " << deputy.name << std::endl;
    //std::cout << "Partido: " << deputy.party << std::endl;
    //std::cout << "Nome do estabelecimento: " << deputy.establishmentName << std::endl;
    std::cout << "Valor do recibo: " << deputy.receiptValue << std::endl;
    printf("\n");
  }

  /*for(unsigned int i=0; i<teste.size();i++){
    std::cout<< teste.at(i) << " ";
  }
  std::cout << std::endl;*/

  return 0;
}
