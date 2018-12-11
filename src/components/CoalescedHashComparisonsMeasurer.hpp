/**
 * @file    CoalescedHashComparisonsMeasurer.hpp
 * @author  Diego Paiva e Silva
 * @date    29/09/2018
 *
 */

#ifndef COALESCEDHASHCOMPARISONSMEASURER_INCLUDED
#define COALESCEDHASHCOMPARISONSMEASURER_INCLUDED

#define EXECUTIONS_AMOUNT 5
#define LOAD_FACTOR 0.75

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo> // typeid
#include <unistd.h>

class CoalescedHashComparisonsMeasurer
{
public:
  CoalescedHashComparisonsMeasurer() {};
  ~CoalescedHashComparisonsMeasurer() {};

  template<typename T>
  void storeComparisonsResults(std::string inFileName, T* hashTable, std::string outFileName = "hash-out.txt")
  {
    // Initialize random seed
    srand(time(NULL));

    std::ifstream inFile(inFileName);

    std::ofstream outFile(outFileName, std::ifstream::app);

    if (!inFile.is_open())
    {
      std::cout << "Falha na leitura do arquivo" << std::endl;
      exit(1);
    }
    else
    {
      int n;

      // Nome do tipo de tabela hash utilizada e data que foi compilado
      outFile << "Resultados para " << typeid(hashTable).name() << " em " << getCurrentTime() << std::endl;

      while (inFile >> n)
      {
        for (int execution = 0; execution < EXECUTIONS_AMOUNT; execution++)
        {
          // Adaptamos a capacidade da tabela ao valor que acabou de ser lido do arquivo
          hashTable->data.clear();
          hashTable->size = (int) n/LOAD_FACTOR;
          hashTable->data.resize(hashTable->size);

          hashTable->pointer.clear();
          hashTable->pointer.resize(hashTable->size);

          for (int i = 0; i < n; i++)
          {
            try
            {
              this->comparisons[execution] = hashTable->insert(rand() % n + 1);
            }
            catch (char const *exception)
            {
              std::cerr << exception << std::endl;
            }
          }

          // Escrita do número de comparações no arquivo de saída
          outFile << "Comparações para N = " << n  << " - Conjunto " << execution + 1 << ": "
                  << this->comparisons[execution] << std::endl;
        }
        outFile << "Número médio de comparações = " << calculateAverageComparisonsAmount() << "\n\n";
      }
    }
    outFile << "===================== Fim do processo =====================\n" << std::endl;
  }

private:
  std::vector<int> randomNumbers;
  int comparisons[EXECUTIONS_AMOUNT];

  char* getCurrentTime()
  {
    time_t _tm = time(NULL);
    struct tm * currentTime = localtime(&_tm);
    return asctime(currentTime);
  }

  double calculateAverageComparisonsAmount()
  {
    double comparisonsSum = 0.0;
    for (int i = 0; i < EXECUTIONS_AMOUNT; i++)
    {
      comparisonsSum += comparisons[i];
    }
    return comparisonsSum/EXECUTIONS_AMOUNT;
  }
};

#endif // COALESCEDHASHCOMPARISONSMEASURER_INCLUDED
