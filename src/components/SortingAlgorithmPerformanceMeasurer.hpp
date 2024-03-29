/**
 * @file    SortingAlgorithmPerformanceMeasurer.hpp
 * @author  Diego Paiva e Silva
 * @date    17/09/2018
 *
 * O propósito da classe SortingAlgorithmPerformanceMeasurer é contabilizar, para um determinado
 * conjunto de dados, o tempo total de execução, o número de comparações e número de trocas realizadas
 * dos algoritmos de ordenação implementados dentro deste projeto. Este conjunto de dados é gerado
 * a partir da leitura de um arquivo que deve ser passado como parâmetro. O arquivo deve estar disposto
 * da seguinte forma:
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
 * afim de registrar o tempo de execução para cada um desses conjuntos e ao fim calcular o tempo médio
 * de execução do algoritmo para aquele valor de "n". O número padrão de execuções para cada valor de
 * "n" é 5. Todos os resultados são gravados em um arquivo de saída.
 */

#ifndef SORTINGALGORITHMPERFORMANCEMEASURER_H_INCLUDED
#define SORTINGALGORITHMPERFORMANCEMEASURER_H_INCLUDED

#define EXECUTIONS_AMOUNT 5

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> // std::setprecision, std::setw
#include <typeinfo> // typeid

// Descomente as duas linhas abaixo se for testar para o Quicksort com deputados
#include "./deputy/file/reader/DeputyFileReader.hpp"
#include "./deputy/Deputy.hpp"

class SortingAlgorithmPerformanceMeasurer
{
public:
  SortingAlgorithmPerformanceMeasurer() {};
  ~SortingAlgorithmPerformanceMeasurer() {};

  template<typename T>
  void storePerformanceResults(std::string inFileName, T* algorithm, std::string outFileName = "saida.txt")
  {
    // Initialize random seed
    srand(time(NULL));

    std::ifstream inFile(inFileName);

    std::ofstream outFile(outFileName, std::ifstream::app);

    // Descomente as duas linhas abaixo se for testar para o Quicksort com deputados
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

      // Nome do algoritmo passado como entrada e data que foi compilado
      outFile << "Resultados para " << typeid(algorithm).name() << " em " << getCurrentTime() << std::endl;

      while(inFile >> n)
      {
        // Adaptamos a capacidade do vector ao valor que acabou de ser lido do arquivo
        randomDeputies.resize(n);

        for (int execution = 0; execution < EXECUTIONS_AMOUNT; execution++)
        {
          for (int i = 0; i < n; i++)
          {
            // Preenchendo com números aleatórios
            // randomNumbers.at(i) = rand() % n + 1;

            // Descomente as duas linhas abaixos se for testar com ids aleatórios dos deputados
            int index = rand() % deputies.size();
            randomDeputies.at(i) = deputies.at(index);
          }

          algorithm->sort(randomDeputies, 0, 10);

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
    inFile.close();
    outFile.close();
  }

private:
  std::vector<int> randomNumbers;
  std::vector<Deputy> randomDeputies;
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

#endif // SORTINGALGORITHMPERFORMANCEMEASURER_H_INCLUDED
