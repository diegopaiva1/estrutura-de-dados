/**
 * @file    HeapSort.hpp
 * @author  Diego Paiva e Silva
 * @date    11/09/2018
 *
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

  void sort(std::vector<int> &unsorted)
  {
    buildMaxHeap(unsorted);
    for(int i = unsorted.size() - 1; i >= 0; i--)
    {
      std::swap(unsorted.at(0), unsorted.at(i));
      maxHeapify(unsorted, 0, unsorted.size() - i);
    }
  }

private:
  void buildMaxHeap(std::vector<int> &unsorted)
  {
    // Selecionamos o indíce do meio do vetor (ou próximo, caso tamanho seja ímpar)
    int middleIndex = floor(unsorted.size()/2);

    for (int i = middleIndex; i >= 0; i--)
    {
      maxHeapify(unsorted, i);
    }
  }

  void maxHeapify(std::vector<int> &unsorted, unsigned int i, int offset = 0)
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
