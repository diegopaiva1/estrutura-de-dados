#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "algorithms/sorting/HeapSort.hpp"

int main(int argc, char const *argv[])
{
  // Arquivo passado por linha de comando
  std::string fileName = argv[1];

  // Initialize random seed
  srand(time(NULL));

  std::ifstream inFile(fileName);

  if (!inFile.is_open())
  {
    std::cout << "Falha na leitura do arquivo" << std::endl;
    exit(1);
  }
  else
  {
    int totalSizes;
    int size;

    HeapSort *heapSort = new HeapSort();

    // Salvando o total de valores possíveis para N
    inFile >> totalSizes;

    std::vector<int> randomNumbers[totalSizes];

    for(int i = 0; inFile >> size; i++)
    {
      for(int k = 0; k < 5; k++)
      {
        for(int j = 0; j < size; j++)
        {
          // Preenchendo com números aleatórios
          randomNumbers[i].push_back(rand() % size + 1);
        }

        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        heapSort->sort(randomNumbers[i]);
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

        printf("Duração da ordenação para N = %6d - Conjunto %1d: %.3fs\n", size, k+1, (double) duration/1000000);
      }
      printf("\n");
    }
  }

  inFile.close();

  return 0;
}
