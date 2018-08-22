/**
 * @file    SelectionSort.h
 * @author  Diego Paiva e Silva
 * @date    11/08/2018
 *
 * O algoritmo SelectionSort é um algoritmo O(n²) instável para ordenação de elementos de uma lista.
 * Esta classe implementa o algoritmo para ordenação de um array de elementos de qualquer tipo.
 * A estratégia consiste em:
 * 1. Supor a existência de duas partições no array: a partição ordenada (inicialmente vazia)
 *    e a partição não-ordenada;
 * 2. Encontrar o menor elemento do array;
 * 3. Trocá-lo de posição com o primeiro elemento da partição não-ordenada e movê-lo para a
 *    partição ordenada;
 * 4. Repetir para os demais elementos não-ordenados.
 */

#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // std::distance, std::swap

class SelectionSort
{
public:
  SelectionSort() {};
  ~SelectionSort() {};

  template<typename T>
  std::vector<T> sort(std::vector<T> &unsorted)
  {
    for (unsigned int i = 0; i < unsorted.size(); i++)
    {
      int minElementIndex = std::distance(unsorted.begin(),
                                          std::min_element(unsorted.begin() + i, unsorted.end()));
      std::swap(unsorted[i], unsorted[minElementIndex]);
    }
    return unsorted;
  }
};

#endif // SELECTIONSORT_H_INCLUDED
