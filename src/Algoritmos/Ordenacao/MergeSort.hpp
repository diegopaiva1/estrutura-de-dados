/**
 * @file    MergeSort.h
 * @author  Diego Paiva e Silva
 * @date    15/08/2018
 *
 * O algoritmo MergeSort é um algoritmo O(nlogn) instável que utiliza o paradigma divisão e conquista
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
      if(hasEvenSize(unsorted))
      {
        firstSliceSize = unsorted.size()/2;
      }
      else
      {
        // Ex: Array de tamanho 17 será divido em duas partições de tamanhos 8 e 9
        firstSliceSize = (unsorted.size() - 1)/2;
      }
      auto firstSlice = generateSubvectorFrom(unsorted, 0, firstSliceSize - 1);
      auto secondSlice = generateSubvectorFrom(unsorted, firstSliceSize, unsorted.size() - 1);
      sort(firstSlice);
      sort(secondSlice);
      generateSortedVectorByMergingTwoSortedVectors(firstSlice, secondSlice, unsorted);
    }
    else
    {
      // O vector já está naturalmente ordenado, pois só contem um único elemento
    }
  }

private:
  template<typename T>
  bool hasEvenSize(std::vector<T> v)
  {
    return v.size() % 2 == 0;
  }

  template<typename T>
  std::vector<T> generateSubvectorFrom(std::vector<T> v, int startingIndex, int lastIndex)
  {
    std::vector<T> subvector;
    for (int i = startingIndex; i <= lastIndex; i++)
    {
      subvector.push_back(v.at(i));
    }
    return subvector;
  }

  template<typename T>
  void generateSortedVectorByMergingTwoSortedVectors(std::vector<T> sorted1, std::vector<T> sorted2,
                                                     std::vector<T> &merged)
  {
    int firstVectorIterator = 0;
    int secondVectorIterator = 0;
    for (unsigned int i = 0; i < sorted1.size() + sorted2.size(); i++)
    {
      if(vectorWasFullyCovered(sorted1, firstVectorIterator) &&
         !vectorWasFullyCovered(sorted2, secondVectorIterator))
      {
        // Basta inserir em merged os elementos do array que não foi todo percorrido
        merged.at(i) = sorted2.at(secondVectorIterator);
        secondVectorIterator++;
      }
      else if(vectorWasFullyCovered(sorted2, secondVectorIterator) &&
              !vectorWasFullyCovered(sorted1, firstVectorIterator))
      {
        merged.at(i) = sorted1.at(firstVectorIterator);
        firstVectorIterator++;
      }
      else {
        // Continuamos comparando os elementos e os inserindo em merged
        if(sorted2.at(secondVectorIterator) < sorted1.at(firstVectorIterator))
        {
          merged.at(i) = sorted2.at(secondVectorIterator);
          secondVectorIterator++;
        }
        else
        {
          merged.at(i) = sorted1.at(firstVectorIterator);
          firstVectorIterator++;
        }
      }
    }
  }

  template<typename T>
  bool vectorWasFullyCovered(std::vector<T> v, int iterator)
  {
    return iterator >= v.size();
  }
};

#endif // MERGESORT_H_INCLUDED
