/**
 * @file    SortingAlgorithmTimeMeasurer.hpp
 * @author  Diego Paiva e Silva
 * @date    17/09/2018
 *
 *  TODO - Class description
 *
 */

#ifndef SORTINGALGORITHMTIMEMEASURER_H_INCLUDED
#define SORTINGALGORITHMTIMEMEASURER_H_INCLUDED

#define EXECUTIONS_AMOUNT 5

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <iomanip> // std::setprecision()
#include <typeinfo> // typeid

typedef std::chrono::high_resolution_clock Time;

class SortingAlgorithmTimeMeasurer
{
public:
  SortingAlgorithmTimeMeasurer() {};
  ~SortingAlgorithmTimeMeasurer() {};

  template<typename T>
  void printResults(std::string fileName, T* algorithm)
  {
    // Initialize random seed
    srand(time(NULL));

    std::ifstream inFile(fileName);

    std::ofstream outFile("saida.txt", std::ifstream::out | std::ifstream::trunc);

    if (!inFile.is_open())
    {
      std::cout << "Falha na leitura do arquivo" << std::endl;
      exit(1);
    }
    else
    {
      int dataSize;

      // Escrevendo o nome do algoritmo passado como entrada
      outFile << "Resultados para " << typeid(algorithm).name() << ":\n" << std::endl;

      while(inFile >> dataSize)
      {
        // Adaptamos a capacidade do vector ao valor que acabou de ser lido do arquivo
        randomNumbers.resize(dataSize);

        for (int execution = 0; execution < EXECUTIONS_AMOUNT; execution++)
        {
          for (int i = 0; i < dataSize; i++)
          {
            // Preenchendo com números aleatórios
            randomNumbers.at(i) = rand() % dataSize + 1;
          }

          // Colhe-se o tempo inicial e final para calcular o tempo total de execução posteriormente
          Time::time_point t1 = Time::now();
          algorithm->sort(randomNumbers);
          Time::time_point t2 = Time::now();

          // Aqui calcula-se o tempo total de execução para o algoritmo de entrada
          double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

          executionTimes[execution] = convertNanosecondsToSeconds(duration);

          // TODO - Abstrair em métodos essas escritas
          outFile << "Tempo de execução para N = " << dataSize  << " - Conjunto " << execution + 1 << ": "
                  << std::setprecision(4) << executionTimes[execution] << "s" << std::endl;
        }
        outFile << "Tempo médio de execução = " << std::setprecision(4) << calculateAverageExecutionTime()
                << "s\n\n";
      }
    }
    inFile.close();
    outFile.close();
  }

private:
  std::vector<int> randomNumbers;
  double executionTimes[EXECUTIONS_AMOUNT];

  double convertNanosecondsToSeconds(double value)
  {
    return (double) value/1000000000;
  }

  double calculateAverageExecutionTime()
  {
    double executionTimesSum = 0.0;
    for(int i = 0; i < EXECUTIONS_AMOUNT; i++)
    {
      executionTimesSum += executionTimes[i];
    }
    return executionTimesSum/EXECUTIONS_AMOUNT;
  }
};

#endif // SORTINGALGORITHMTIMEMEASURER_H_INCLUDED
