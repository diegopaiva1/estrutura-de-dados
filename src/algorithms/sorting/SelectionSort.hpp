/**
 * @file    SelectionSort.hpp
 * @author  Diego Paiva e Silva
 * @date    11/08/2018
 *
 * O algoritmo SelectionSort é um algoritmo O(n²) instável para ordenação de elementos de uma lista.
 * Esta classe implementa o algoritmo para ordenação de um array de elementos de QUALQUER tipo.
 * A estratégia consiste em:
 * 1. Supor a existência de duas partições no array: a partição ordenada (inicialmente vazia)
 *    e a partição não-ordenada;
 * 2. Encontrar o menor elemento da partição não ordenada;
 * 3. Trocá-lo de posição com o primeiro elemento da partição não-ordenada e movê-lo para a
 *    partição ordenada;
 * 4. Repetir para os demais elementos não-ordenados.
 */

#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm> // std::swap
#include <chrono>
#include <time.h>

typedef std::chrono::high_resolution_clock Time;

class SelectionSort
{
public:
  long long int comparisons;
  long long int copies;
  double executionTime;

  SelectionSort() {};
  ~SelectionSort() {};

  template <typename T>
  void sort(std::vector<T> &unsorted)
  {
    this->comparisons = 0;
    this->copies = 0;
    this->executionTime = 0.0;

    Time::time_point t1 = Time::now(); // Tempo inicial de execução

    for (int i = 0; i < unsorted.size(); i++)
    {
      this->copies += 2;
      auto minElement = unsorted.at(i);
      int minElementIndex = i;

      for (int j = i; j < unsorted.size(); j++)
      {
        this->comparisons++;
        if(unsorted.at(j) < minElement)
        {
          this->copies += 2;
          minElement = unsorted.at(j);
          minElementIndex = j;
        }
      }
      std::swap(unsorted.at(i), unsorted.at(minElementIndex));
      this->copies++;
    }

    Time::time_point t2 = Time::now(); // Tempo final de execução

    // Aqui calcula-se o tempo total de execução para o algoritmo
    this->executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    // Nanosegundos para segundos
    this->executionTime = this->executionTime/1000000000;
  }
};

#endif // SELECTIONSORT_H_INCLUDED
