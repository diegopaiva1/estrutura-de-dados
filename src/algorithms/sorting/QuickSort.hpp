#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>

typedef std::chrono::high_resolution_clock Time;

#include "InsertionSort.hpp"

class QuickSort
{
public:
  long long int comparisons;
  long long int copies;
  double executionTime;

  QuickSort() {};
  ~QuickSort() {};

  template<typename T>
  void sort(std::vector<T> &unsorted, int k = 0, int n = 0)
  {
    this->comparisons = 0;
    this->copies = 0;
    this->executionTime = 0.0;

    Time::time_point t1 = Time::now(); // Tempo inicial de execução
    sort(unsorted, 0, unsorted.size() - 1, k, n);
    Time::time_point t2 = Time::now(); // Tempo final de execução

    // Aqui calcula-se o tempo total de execução para o algoritmo
    this->executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    // Nanosegundos para segundos
    this->executionTime = this->executionTime/1000000000;
  }

private:
  template<typename T>
  void sort(std::vector<T> &unsorted, int firstIndex, int lastIndex, int k, int n)
  {
    // InsertionSort que será usado para cálculo da mediana e para o QuickInsertion
    InsertionSort *insertionSort = new InsertionSort();
    copies++;

    // Determinação do pivô
    T pivot;

    if (k == 0)
    {
      pivot = unsorted.at((firstIndex + lastIndex + 1) / 2);
      copies++;
    }
    else
    {
      std::vector<T> elementsMedian;
      for (int i = 0; i < k; i++)
      {
        int index = rand() % (lastIndex - firstIndex + 1) + firstIndex;
        elementsMedian.push_back(unsorted.at(index));
        copies++;
      }
      insertionSort->sort(elementsMedian);
      pivot = elementsMedian.at((elementsMedian.size() - 1) / 2);
      copies++;
    }

    // Particionamento
    int leftPointer = firstIndex;
    int rightPointer = lastIndex;
    copies += 2;

    comparisons++;
    while (leftPointer < rightPointer)
    {
      comparisons++;
      while (unsorted.at(leftPointer) < pivot && leftPointer < lastIndex)
      {
        leftPointer++;
        copies++;
        comparisons++;
      }
      comparisons++;
      while (unsorted.at(rightPointer) > pivot && rightPointer > firstIndex)
      {
        rightPointer--;
        copies++;
        comparisons++;
      }
      comparisons++;
      if (leftPointer < rightPointer)
      {
        comparisons++;
        if(unsorted.at(leftPointer) != unsorted.at(rightPointer))
        {
          std::swap(unsorted.at(leftPointer), unsorted.at(rightPointer));
          copies += 3;
        }
        else
        {
          leftPointer++;
          std::swap(unsorted.at(leftPointer), unsorted.at(rightPointer));
          copies += 4;
        }
      }
      comparisons++;
    }

    // Ordenação das sublistas recursivamente
    comparisons++;
    if (firstIndex < rightPointer)
    {
      if ((lastIndex - firstIndex) <= n)
      {
        insertionSort->sort(unsorted, firstIndex, rightPointer - 1);
      }
      else
      {
        sort(unsorted, firstIndex, rightPointer - 1, k, n);
      }
    }
    comparisons++;
    if (leftPointer < lastIndex)
    {
      if ((lastIndex - firstIndex) <= n)
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
