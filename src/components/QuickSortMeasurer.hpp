/**
 * @file    QuickSortMeasurer.hpp
 * @author  Diego Paiva e Silva
 * @date    17/09/2018
 *
 */

#ifndef QUICKSORTMEASURER_H_INCLUDED
#define QUICKSORTMEASURER_H_INCLUDED

#define EXECUTIONS_AMOUNT 5

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> // std::setprecision, std::setw
#include <typeinfo> // typeid

class QuickSortMeasurer
{
public:
  QuickSortMeasurer() {};
  ~QuickSortMeasurer() {};

  template<typename T>
  void storePerformanceResults(std::string inFileName, T* algorithm, bool isMediana, bool isInsercao, int k, int m, std::string outFileName = "saida.txt")
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

      // Nome do algoritmo passado como entrada e data que foi compilado
      outFile << "Resultados para " << typeid(algorithm).name() << " em " << getCurrentTime() << std::endl;

      while (inFile >> n)
      {
        randomNumbers.resize(n);

        for (int execution = 0; execution < EXECUTIONS_AMOUNT; execution++)
        {
          for (int i = 0; i < n; i++)
            randomNumbers.at(i) = rand() % n + 1;

          if (isMediana)
            algorithm->sort(randomNumbers, k);
          else if (isInsercao)
            algorithm->sort(randomNumbers, 0, m);

          this->comparisons[execution] = algorithm->comparisons;
          this->copies[execution] = algorithm->copies;
          this->executionTimes[execution] = algorithm->executionTime;

          // Escrita das métricas colhidas no arquivo de saída
          outFile << "Tempo de execução para " << std::setw(11) << "N = " << n
                  << " - Conjunto " << execution + 1 << ": " << std::setprecision(4)
                  << this->executionTimes[execution] << "s" << std::endl;
          outFile << "Número de comparações para " << std::setw(7) << "N = " << n
                  << " - Conjunto " << execution + 1 << ": " << this->comparisons[execution] << std::endl;
          outFile << "Número de cópias geradas para N = " << n << " - Conjunto " << execution + 1 << ": "
                  << this->copies[execution] << "\n\n";
        }
        outFile << "Tempo médio de execução = " << std::setprecision(4)
                << calculateAverage(this->executionTimes) << "s\n";
        outFile << "Número médio de comparações = " << calculateAverage(this->comparisons) << std::endl;
        outFile << "Número médio de cópias geradas = " << calculateAverage(this->copies) << "\n\n";
        outFile << "===========================================================\n" << std::endl;
      }
    }
    outFile << "===================== Fim do processo =====================\n" << std::endl;
  }

private:
  std::vector<int> randomNumbers;
  double executionTimes[EXECUTIONS_AMOUNT];
  long long int comparisons[EXECUTIONS_AMOUNT];
  long long int copies[EXECUTIONS_AMOUNT];

  char* getCurrentTime()
  {
    time_t _tm = time(NULL);
    struct tm * currentTime = localtime(&_tm);
    return asctime(currentTime);
  }

  template <typename T>
  double calculateAverage(T* array)
  {
    double sum = 0.0;
    for (int i = 0; i < EXECUTIONS_AMOUNT; i++)
    {
      sum += array[i];
    }
    return sum/EXECUTIONS_AMOUNT;
  }
};

#endif // QUICKSORTMEASURER_H_INCLUDED
