/**
 * @file    HeapSort.hpp
 * @author  Diego Paiva e Silva
 * @date    11/09/2018
 *
 * O algoritmo HeapSort é um algoritmo O(nlogn) instável que utiliza a estrutura de dados Heap
 * para ordenação de elementos de uma lista.
 * Esta classe implementa o algoritmo para ordenação de um vector para elementos de QUALQUER tipo.
 * O algoritmo utiliza em seu favor o fato de ter a garantia que o maior elemento de um max-heap está
 * sempre na primeira posição (indice = 0).
 * A estratégia consiste em:
 * 1. Dado o conjunto a ser ordenado, transformá-lo em um max-heap;
 * 2. Trocar o maior elemento (indice = 0) de posição com o último elemento da heap. Portanto o elemento
 *    que foi pra última posição já está ordenado;
 * 3. Transformar o conjunto remanescente desordenado em um max-heap;
 * 4. Repetir os passos 2 e 3 até que o conjunto remanescente esteja completamente ordenado.
 */

#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm> // std::swap

class HeapSort
{
public:
  HeapSort() {};
  ~HeapSort() {};

  template <typename T>
  void sort(std::vector<T> &unsorted)
  {
    buildMaxHeap(unsorted);
    for(int i = unsorted.size() - 1; i >= 0; i--)
    {
      std::swap(unsorted.at(0), unsorted.at(i));
      maxHeapify(unsorted, 0, unsorted.size() - i);
    }
  }

private:
  template <typename T>
  void buildMaxHeap(std::vector<T> &unsorted)
  {
    // Selecionamos o indíce mais próximo ao meio do vetor
    int middleIndex = floor(unsorted.size()/2);

    for (int i = middleIndex; i >= 0; i--)
    {
      maxHeapify(unsorted, i);
    }
  }

  template <typename T>
  /* O valor do offset ser igual a 0 signfica que estamos estamos aplicando o algoritmo
   * á toda extensão do vetor. Caso não seja igual a 0, aplicamos até unsorted.size() - offset.
   */
  void maxHeapify(std::vector<T> &unsorted, unsigned int i, int offset = 0)
  {
    unsigned int leftChildIndex  = 2 * i + 1;
    unsigned int rightChildIndex = 2 * i + 2;
    unsigned int maxIndex = i;

    if(leftChildIndex < unsorted.size() - offset && unsorted.at(leftChildIndex) > unsorted.at(i))
    {
      maxIndex = leftChildIndex;
    }

    if(rightChildIndex < unsorted.size() - offset && unsorted.at(rightChildIndex) > unsorted.at(maxIndex))
    {
      maxIndex = rightChildIndex;
    }

    if(maxIndex != i)
    {
      std::swap(unsorted.at(i), unsorted.at(maxIndex));
      maxHeapify(unsorted, maxIndex, offset);
    }
  }
};

#endif // HEAPSORT_H_INCLUDED
