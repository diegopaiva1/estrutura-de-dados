#include <iostream>
#include <string>
#include <vector>

#include "./Algoritmos/Ordenacao/SelectionSort.hpp"

int main(int argc, char const *argv[])
{
  std::vector<std::string> names = {"Diego", "Manoel", "Isabella", "Maria de Lourdes", "Orony", "Aldivino"};
  SelectionSort *selectionSort = new SelectionSort();
  auto sortedNames = selectionSort->sort(names);
  for (unsigned int i = 0; i < sortedNames.size(); i++)
  {
    std::cout << sortedNames.at(i) << " ";
  }
  printf("\n");
  return 0;
}


