#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

#include <iostream>
#include <vector>

#include "InsertionSort.hpp"

class QuickSort
{
public:
  QuickSort() {};
  ~QuickSort() {};

  template<typename T>
  void sort(std::vector<T> &unsorted, int k = 0, int n = 0)
  {
    sort(unsorted, 0, unsorted.size() - 1, k, n);
  }

private:
  template<typename T>
  void sort(std::vector<T> &unsorted, int firstIndex, int lastIndex, int k, int n)
  {
    // InsertionSort que será usado para cálculo da mediana e para o QuickInsertion
    InsertionSort *insertionSort = new InsertionSort();
    // Determinação do pivô
    T pivot;
    if (k == 0)
    {
      pivot = unsorted.at((firstIndex + lastIndex + 1) / 2);
    }
    else
    {
      std::vector<T> elementsMedian;
      for(int i = 0; i < k; i++)
      {
        int index = rand() % (lastIndex - firstIndex + 1) + firstIndex;
        elementsMedian.push_back(unsorted.at(index));
      }
      insertionSort->sort(elementsMedian);
      pivot = elementsMedian.at((elementsMedian.size() - 1) / 2);
    }
    // Particionamento
    int leftPointer = firstIndex;
    int rightPointer = lastIndex;

    while (leftPointer < rightPointer)
    {
      while (unsorted.at(leftPointer) < pivot && leftPointer < lastIndex)
      {
        leftPointer++;
      }
      while (unsorted.at(rightPointer) > pivot && rightPointer > firstIndex)
      {
        rightPointer--;
      }
      if (leftPointer < rightPointer)
      {
        if(unsorted.at(leftPointer) != unsorted.at(rightPointer))
        {
          std::swap(unsorted.at(leftPointer), unsorted.at(rightPointer));
        }
        else
        {
          leftPointer++;
          std::swap(unsorted.at(leftPointer), unsorted.at(rightPointer));
        }
      }
    }

    // Ordenação das sublistas recursivamente
    if (firstIndex < rightPointer)
    {
      if((lastIndex - firstIndex) <= n)
      {
        insertionSort->sort(unsorted, firstIndex, rightPointer - 1);
      }
      else
      {
        sort(unsorted, firstIndex, rightPointer - 1, k, n);
      }
    }
    if (leftPointer < lastIndex)
    {
      if((lastIndex - firstIndex) <= n)
      {
        insertionSort->sort(unsorted, leftPointer + 1, lastIndex);
      }
      else
      {
        sort(unsorted, leftPointer + 1, lastIndex, k, n);
      }
    }
  }
};

#endif // QUICKSORT_H_INCLUDED
