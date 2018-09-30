/**
 * @file    HashTableComparisonsMeasurer.hpp
 * @author  Diego Paiva e Silva
 * @date    29/09/2018
 *
 *  TODO - Description
 */

#ifndef HASHTABLECOMPARISONSMEASURER_H_INCLUDED
#define HASHTABLECOMPARISONSMEASURER_H_INCLUDED

#define EXECUTIONS_AMOUNT 5
#define DEFAULT_LOAD_FACTOR 0.75

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <typeinfo> // typeid
#include <unistd.h>

#include "./deputy/file/reader/DeputyFileReader.hpp"
#include "./deputy/Deputy.hpp"

class HashTableComparisonsMeasurer
{
public:
  HashTableComparisonsMeasurer() {};
  ~HashTableComparisonsMeasurer() {};

  template<typename T>
  void storeComparisonsResults(std::string inFileName, T* hashTable, std::string outFileName = "hash-out.txt")
  {
    // Initialize random seed
    srand(time(NULL));

    std::ifstream inFile(inFileName);

    std::ofstream outFile(outFileName, std::ifstream::app);

    DeputyFileReader *deputyFileReader = new DeputyFileReader();
    std::vector<Deputy> deputies = deputyFileReader->constructDeputies("dataset/deputies.csv");

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
        int index;

        for (int execution = 0; execution < EXECUTIONS_AMOUNT; execution++)
        {
          // Adaptamos a capacidade da tabela ao valor que acabou de ser lido do arquivo
          hashTable->data.clear();
          hashTable->size = (int) n/DEFAULT_LOAD_FACTOR;
          hashTable->data.resize(hashTable->size);

          for (int i = 0; i < n; i++)
          {
            try
            {
              // Preenchendo com números aleatórios
              index = rand() % (deputies.size() - 1) + 0;
              hashTable->insert(deputies.at(index).id);
            }
            catch (char const* exception)
            {
              std::cerr << exception << std::endl;
            }
          }

          // Obtendo o último dado inserido na tabela
          int comparisons = hashTable->get(deputies.at(index).id);

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

#endif // HASHTABLECOMPARISONSMEASURER_H_INCLUDED
