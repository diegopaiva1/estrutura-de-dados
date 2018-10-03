/**
 * @file    MergeSort.hpp
 * @author  Diego Paiva e Silva
 * @date    15/08/2018
 *
 * O algoritmo MergeSort é um algoritmo O(nlogn) instável que utiliza o paradigma divisão e conquista
 * para ordenação de elementos de uma lista.
 * Esta classe implementa o algoritmo para ordenação de um vector para elementos de QUALQUER tipo.
 * A estratégia consiste em:
 * 1. Dada uma lista de N números, dividi-la até que obtenham-se N listas de tamanho 1 (recursivamente);
 * 2. Partindo da ideia de que uma lista com um único elemento já está naturalmente ordenada,
 *    basta realizar, duas a duas, a união ordenada das listas resultantes da divisão;
 * 3. A cada passo o algoritmo gera novas listas ordenadas com mais elementos (volta da recursão);
 * 4. Ir realizando a união ordenada das listas até que se obtenha uma única lista ordenada com todos os elementos.
 */

#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>

typedef std::chrono::high_resolution_clock Time;

class MergeSort
{
public:
  long long int comparisons;
  long long int copies;
  double executionTime;

  MergeSort() {};
  ~MergeSort() {};

  template <typename T>
  void sort(std::vector<T> &unsorted)
  {
    // O vetor auxiliar serve pra armazenar os valores durante o merge que irão ao vetor original
    std::vector<T> aux (unsorted.size());
    sort(unsorted, 0, unsorted.size() - 1, aux);
  }

private:
  template <typename T>
  void sort(std::vector<T> &unsorted, int firstIndex, int lastIndex, std::vector<T> &aux)
  {
    this->comparisons = 0;
    this->copies = 0;
    this->executionTime = 0.0;

    Time::time_point t1 = Time::now(); // Tempo inicial de execução

    comparisons++;
    if (firstIndex != lastIndex)
    {
      int midIndex;

      comparisons++;
      if (hasEvenAmountOfPositions(firstIndex, lastIndex))
      {
        // Exatamente a posição do meio
        midIndex = (firstIndex + lastIndex + 1)/2;
        copies++;
      }
      else
      {
        // Ex: Em um vector de tamanho 17, a posição do meio será igual a 8
        midIndex = (firstIndex + lastIndex)/2;
        copies++;
      }
      sort(unsorted, firstIndex, midIndex - 1, aux);
      sort(unsorted, midIndex, lastIndex, aux);
      merge(unsorted, firstIndex, midIndex, lastIndex, aux);
    }
    else
    {
      // O vector já está naturalmente ordenado, pois só contem um único elemento
      return;
    }

    Time::time_point t2 = Time::now(); // Tempo final de execução

    // Aqui calcula-se o tempo total de execução para o algoritmo
    this->executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    // Nanosegundos para segundos
    this->executionTime = this->executionTime/1000000000;
  }

  bool hasEvenAmountOfPositions(int firstIndex, int lastIndex)
  {
    return ( (firstIndex + lastIndex + 1) % 2 == 0);
  }

  template <typename T>
  void merge(std::vector<T> &v, int firstIndex, int midIndex, int lastIndex, std::vector<T> &aux)
  {
    int leftSliceIterator = firstIndex;
    int rightSliceIterator = midIndex;
    copies += 2;

    for (int i = firstIndex; i <= lastIndex; i++)
    {
      comparisons += 2;
      if (leftSliceIterator >= midIndex && rightSliceIterator <= lastIndex)
      {
        // Basta inserir os elementos na partição à direita
        aux.at(i) = v.at(rightSliceIterator);
        rightSliceIterator++;
        copies += 2;
      }
      else if (rightSliceIterator > lastIndex && leftSliceIterator < midIndex)
      {
        // Basta inserir os elementos na partição à esquerda
        aux.at(i) = v.at(leftSliceIterator);
        leftSliceIterator++;
        copies += 2;
      }
      else
      {
        comparisons++;
        // Seguimos comparando os elementos de cada partição
        if (v.at(leftSliceIterator) < v.at(rightSliceIterator))
        {
          aux.at(i) = v.at(leftSliceIterator);
          leftSliceIterator++;
          copies += 2;
        }
        else
        {
          aux.at(i) = v.at(rightSliceIterator);
          rightSliceIterator++;
          copies += 2;
        }
      }
    }

    // Copiando de volta
    for (int i = firstIndex; i <= lastIndex; i++)
    {
      v.at(i) = aux.at(i);
      copies++;
    }
  }

};

#endif // MERGESORT_H_INCLUDED
