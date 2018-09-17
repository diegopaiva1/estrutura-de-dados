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

    if (!inFile.is_open())
    {
      std::cout << "Falha na leitura do arquivo" << std::endl;
      exit(1);
    }
    else
    {
      int dataSize;

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

          // Colhe-se o tempo iniciail e final para calcular o tempo total de execução posteriormente
          Time::time_point t1 = Time::now();
          algorithm->sort(randomNumbers);
          Time::time_point t2 = Time::now();

          // Aqui calcula-se o tempo total de execução para o algoritmo de entrada
          double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

          executionTimes[execution] = convertNanosecondsToSeconds(duration);

          printf("Tempo de execução para N = %6d - Conjunto %1d: %.4fs\n",
                 dataSize, execution + 1, executionTimes[execution]);
        }
        printf("Tempo médio de execução = %.4fs\n\n", calculateAverageExecutionTime());
      }
    }
    inFile.close();
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
