/**
 * @file    MergeSort.h
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

#include "../../Utils/VectorUtils.hpp"

class MergeSort
{
public:
  MergeSort() {};
  ~MergeSort() {};

  template<typename T>
  void sort(std::vector<T> &unsorted)
  {
    if(unsorted.size() != 1)
    {
      int firstSliceSize;
      if(VectorUtils::hasEvenSize(unsorted))
      {
        firstSliceSize = unsorted.size()/2;
      }
      else
      {
        // Ex: Array de tamanho 17 será divido em duas partições de tamanhos 8 e 9
        firstSliceSize = (unsorted.size() - 1)/2;
      }
      auto firstSlice  = VectorUtils::generateSubvectorFrom(unsorted, 0, firstSliceSize - 1);
      auto secondSlice = VectorUtils::generateSubvectorFrom(unsorted, firstSliceSize, unsorted.size() - 1);
      sort(firstSlice);
      sort(secondSlice);
      VectorUtils::generateSortedVectorByMergingTwoSortedVectors(firstSlice, secondSlice, unsorted);
    }
    else
    {
      // O vector já está naturalmente ordenado, pois só contem um único elemento
      return;
    }
  }
};

#endif // MERGESORT_H_INCLUDED
