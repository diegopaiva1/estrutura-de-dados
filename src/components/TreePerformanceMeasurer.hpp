/**
 * @file    TreePerformanceMeasurer.hpp
 * @author  Diego Paiva e Silva
 * @date    07/11/2018
 *
 * O propósito da classe TreePerformanceMeasurer é contabilizar, para um determinado
 * conjunto de dados, o tempo total de execução, o número de comparações e número de cópias realizadas
 * das árvores balanceadas implementadas dentro deste projeto. Este conjunto de dados é gerado
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
#include <chrono>
#include <time.h>

typedef std::chrono::high_resolution_clock Time;

#include "./deputy/file/reader/DeputyFileReader.hpp"
#include "./deputy/Deputy.hpp"

class TreePerformanceMeasurer
{
public:
  TreePerformanceMeasurer() {};
  ~TreePerformanceMeasurer() {};

  template<typename T>
  void storePerformanceResults(std::string inFileName, T* tree, std::string outFileName = "saidaArvore.txt")
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

      // Tipo da árvore passada como entrada e data que foi compilado
      outFile << "Resultados para " << typeid(tree).name() << " em " << getCurrentTime() << std::endl;

      while(inFile >> n)
      {
        for (int execution = 0; execution < EXECUTIONS_AMOUNT; execution++)
        {

          for (int i = 0; i < n; i++)
          {
            auto gasto = deputies.at(rand() % deputies.size()).gasto_id;
            tree->insert(gasto);
          }

          tree->copies = 0;
          tree->comparisons = 0;


          // Teste do tempo de busca
          Time::time_point t1 = Time::now(); // Tempo inicial de execução
          for (int i = 0; i < n; i++)
          {
            auto gasto = deputies.at(rand() % deputies.size()).gasto_id;
            tree->get(gasto);
          }
          Time::time_point t2 = Time::now(); // Tempo final de execução

          // Aqui calcula-se o tempo total de execução para o algoritmo
          double executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
          // Nanosegundos para segundos
          executionTime = executionTime/1000000000;

          this->comparisons[execution] = tree->comparisons;
          this->copies[execution] = tree->copies;
          this->executionTimes[execution] = executionTime;

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
