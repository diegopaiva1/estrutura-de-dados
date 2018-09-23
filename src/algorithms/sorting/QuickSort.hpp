#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

#include <iostream>
#include <vector>

class QuickSort
{
public:
  QuickSort() {};
  ~QuickSort() {};

  template<typename T>
  void sort(std::vector<T> &unsorted, int k = 0)
  {
    sort(unsorted, 0, unsorted.size() - 1, k);
  }

private:
  template<typename T>
  void sort(std::vector<T> &unsorted, int firstIndex, int lastIndex, int k)
  {
    // Determinação do pivô
    T pivot;
    if (k == 0){
      pivot = unsorted.at((firstIndex+lastIndex)/2);
    }

    // Particionamento
    int leftPointer = firstIndex;
    int rightPointer = lastIndex;

    while (leftPointer < rightPointer)
    {
      while (unsorted.at(leftPointer) < pivot && leftPointer < lastIndex)
      {
        leftPointer = leftPointer + 1;
      }
      while (unsorted.at(rightPointer) > pivot && rightPointer > firstIndex)
      {
        rightPointer = rightPointer - 1;
      }
      if (leftPointer < rightPointer)
      {
        std::swap(unsorted.at(leftPointer), unsorted.at(rightPointer));
        leftPointer = leftPointer + 1;
        rightPointer = rightPointer - 1;
      }
    }

    // Ordenação das sublistas recursivamente
    if (firstIndex < rightPointer)
    {
      sort(unsorted, firstIndex, rightPointer, k);
    }
    if (leftPointer < lastIndex)
    {
      sort(unsorted, leftPointer+1, lastIndex, k);
    }
  }
};

#endif // QUICKSORT_H_INCLUDED
