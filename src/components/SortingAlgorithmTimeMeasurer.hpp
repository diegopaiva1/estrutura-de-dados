/**
 * @file    SortingAlgorithmTimeMeasurer.hpp
 * @author  Diego Paiva e Silva
 * @date    17/09/2018
 *
 * O propósito da classe SortingAlgorithmTimeMeasurer é contabilizar, para um determinado conjunto de dados,
 * o tempo total de execução dos algoritmos de ordenação implementados dentro deste projeto.
 * Este conjunto de dados é gerado a partir da leitura de um arquivo que deve ser passado como parâmetro.
 * O arquivo deve estar disposto da seguinte forma:
 *
 * n1
 * n2
 * n3
 * ...
 * nf
 *
 * Tal que n1, n2, n3, ..., nf são valores inteiros e "nf" representa o ultimo valor do arquivo.
 * Para cada linha lida do arquivo, o vetor de números adere à capacidade correspondente ao valor
 * de "n" da linha lida. O vetor é completamente preenchido com valores aleatórios para poder servir ao
 * algoritmo que é passado por parâmetro.
 * Para cada valor de "n" lido, podem-se realizar várias execuções com conjuntos de valores diferentes,
 * para que se possa registrar o tempo de execução para cada um desses conjuntos e ao fim calcular o
 * tempo médio de execução do algoritmo para aquele valor de "n". O número padrão de execuções para cada
 * valor de "n" é 5. Todos os resultados são gravados em um arquivo de saída.
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
#include <time.h>

typedef std::chrono::high_resolution_clock Time;

class SortingAlgorithmTimeMeasurer
{
public:
  SortingAlgorithmTimeMeasurer() {};
  ~SortingAlgorithmTimeMeasurer() {};

  template<typename T>
  void printResults(std::string inFileName, T* algorithm, std::string outFileName = "saida.txt")
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
      outFile << "Resultados para " << typeid(algorithm).name()
              << " em " << getCurrentTime() << std::endl;

      while(inFile >> n)
      {
        // Adaptamos a capacidade do vector ao valor que acabou de ser lido do arquivo
        randomNumbers.resize(n);

        for (int execution = 0; execution < EXECUTIONS_AMOUNT; execution++)
        {
          for (int i = 0; i < n; i++)
          {
            // Preenchendo com números aleatórios
            randomNumbers.at(i) = rand() % n + 1;
          }

          // Colhe-se o tempo inicial e final para calcular o tempo total de execução posteriormente
          Time::time_point t1 = Time::now();
          algorithm->sort(randomNumbers);
          Time::time_point t2 = Time::now();

          // Aqui calcula-se o tempo total de execução para o algoritmo de entrada
          double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

          executionTimes[execution] = convertNanosecondsToSeconds(duration);

          // Escrita do tempo de execução no arquivo de saída
          outFile << "Tempo de execução para N = " << n  << " - Conjunto " << execution + 1 << ": "
                  << std::setprecision(4) << executionTimes[execution] << "s" << std::endl;
        }
        outFile << "Tempo médio de execução = " << std::setprecision(4) << calculateAverageExecutionTime()
                << "s\n\n";
      }
    }
    outFile << "===================== Fim do processo =====================\n" << std::endl;
    inFile.close();
    outFile.close();
  }

private:
  std::vector<int> randomNumbers;
  double executionTimes[EXECUTIONS_AMOUNT];

  char* getCurrentTime()
  {
    time_t _tm = time(NULL);
    struct tm * currentTime = localtime(&_tm);
    return asctime(currentTime);
  }

  double convertNanosecondsToSeconds(double value)
  {
    return (double) value/1000000000;
  }

  double calculateAverageExecutionTime()
  {
    double executionTimesSum = 0.0;
    for (int i = 0; i < EXECUTIONS_AMOUNT; i++)
    {
      executionTimesSum += executionTimes[i];
    }
    return executionTimesSum/EXECUTIONS_AMOUNT;
  }
};

#endif // SORTINGALGORITHMTIMEMEASURER_H_INCLUDED
