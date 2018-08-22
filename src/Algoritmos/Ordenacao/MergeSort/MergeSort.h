/**
 * @file    MergeSort.h
 * @author  Diego Paiva e Silva
 * @date    15/08/2018
 *
 * O algoritmo MergeSort é um algoritmo O(nlogn) instável? que utiliza o paradigma divisão e conquista
 * para ordenação de elementos de uma lista.
 * Esta classe implementa o algoritmo para ordenação de um array de inteiros.
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

#include "../../../Utils/ArrayUtils/ArrayUtils.h"

class MergeSort
{
public:

  MergeSort() {};
  ~MergeSort() {};

  template<typename T>
  std::vector<T> sort(std::vector<T> unsorted)
  {
    std::vector<T> sorted;
    if(unsorted.size() == 1)
    {
      // Uma lista com um único elemento já está naturalmente ordenada
      sorted = unsorted;
      return sorted;
    }
    else
    {
      int firstSliceSize;
      if(unsorted.size() % 2 == 0)
      {
        firstSliceSize  = unsorted.size()/2;
      }
      else
      {
        // Ex: Array de tamanho 17 será divido em duas partições de tamanhos 8 e 9
        firstSliceSize  = (unsorted.size() - 1)/2;
      }
      std::vector<T> firstSlice = getSubvectorFrom(unsorted, 0, firstSliceSize - 1);
      std::vector<T> secondSlice = getSubvectorFrom(unsorted, firstSliceSize, unsorted.size() - 1);
      sort(firstSlice);
      sort(secondSlice);
      sorted = generateSortedVectorByMergingTwoSortedVectors(firstSlice, secondSlice);
    }
    return sorted;
  }

private:

  template<typename T>
  std::vector<T> getSubvectorFrom(std::vector<T> v, int startingIndex, int lastIndex)
  {
    std::vector<T> subvector;
    for (int i = startingIndex; i <= lastIndex; i++)
    {
      subvector.push_back(v.at(i));
    }
    return subvector;
  }

  template<typename T>
  std::vector<T> generateSortedVectorByMergingTwoSortedVectors(std::vector<T> sorted1,
                                                               std::vector<T> sorted2)
  {
    std::vector<T> merged;
    int firstVectorIterator = 0;
    int secondVectorIterator = 0;
    for (int i = 0; i < sorted1.size() + sorted2.size(); i++)
    {
      if(vectorWasFullyCovered(sorted1, firstVectorIterator) && !vectorWasFullyCovered(sorted2, secondVectorIterator))
      {
        // Basta inserir em merged os elementos do array que não foi todo percorrido
        merged.insert(merged.begin() + i, sorted2.at(secondVectorIterator));
        secondVectorIterator++;
      }
      else if(vectorWasFullyCovered(sorted2, secondVectorIterator) && !vectorWasFullyCovered(sorted1, firstVectorIterator))
      {
        merged.insert(merged.begin() + i, sorted1.at(firstVectorIterator));
        firstVectorIterator++;
      }
      else {
        // Continuamos comparando os elementos e os inserindo em merged
        if(sorted2.at(secondVectorIterator) < sorted1.at(firstVectorIterator))
        {
          merged.insert(merged.begin() + i, sorted2.at(secondVectorIterator));
          secondVectorIterator++;
        }
        else
        {
          merged.insert(merged.begin() + i, sorted1.at(firstVectorIterator));
          firstVectorIterator++;
        }
      }
    }
    return merged;
  }

  template<typename T>
  bool vectorWasFullyCovered(std::vector<T> v, int iterator)
  {
    return iterator >= v.size();
  }
};

#endif // MERGESORT_H_INCLUDED
