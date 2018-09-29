/**
 * @file    HashTablePerfomanceMeasurer.hpp
 * @author  Diego Paiva e Silva
 * @date    29/09/2018
 *
 *  TODO - Description
 */

#ifndef SORTINGALGORITHMTIMEMEASURER_H_INCLUDED
#define SORTINGALGORITHMTIMEMEASURER_H_INCLUDED

#define EXECUTIONS_AMOUNT 5
#define DEFAULT_LOAD_FACTOR 0.75

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo> // typeid
#include <unistd.h>

class HashTablePerfomanceMeasurer
{
public:
  HashTablePerfomanceMeasurer() {};
  ~HashTablePerfomanceMeasurer() {};

  template<typename T>
  void storePerfomanceResults(std::string inFileName, T* hashTable, std::string outFileName = "hash-out.txt")
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

      // Nome do algoritmo de tratamento de colisão utilizado e data que foi compilado
      outFile << "Resultados para " << typeid(hashTable).name() << " em " << getCurrentTime() << std::endl;

      while (inFile >> n)
      {
        int randomValue;

        for (int execution = 0; execution < EXECUTIONS_AMOUNT; execution++)
        {
          // Adaptamos a capacidade da tabela ao valor que acabou de ser lido do arquivo
          hashTable->data.clear();
          hashTable->size = (int) n/DEFAULT_LOAD_FACTOR;
          hashTable->data.resize(hashTable->size);

          for (int i = 0; i < n; i++)
          {
            // Preenchendo com números aleatórios
            randomValue = rand() % n + 1;
            try
            {
              hashTable->insert(randomValue);
            }
            catch (char const* exception)
            {
              std::cerr << exception << std::endl;
            }
          }

          // Obtendo o último dado inserido na tabela
          int comparisons = hashTable->get(randomValue);

          this->comparisons[execution] = comparisons;

          // Escrita do número de comparações no arquivo de saída
          outFile << "Comparações para N = " << n  << " - Conjunto " << execution + 1 << ": "
                  << this->comparisons[execution] << std::endl;
        }
        outFile << "Número médio de comparações = " << calculateAverageComparisonsAmount() << "\n\n";
      }
    }
    outFile << "===================== Fim do processo =====================\n" << std::endl;
    inFile.close();
    outFile.close();
  }

private:
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

#endif // SORTINGALGORITHMTIMEMEASURER_H_INCLUDED
