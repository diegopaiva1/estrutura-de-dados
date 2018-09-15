#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

#include <iostream>

class QuickSort
{
public:
  QuickSort() {};
  ~QuickSort() {};

  template<typename T>
  void sort(std::vector<T> &unsorted)
  {
    sort(unsorted, 0, unsorted.size() - 1);
  }

  template<typename T>
  void sortInsertion(std::vector<T> &unsorted)
  {
    int i,j;
    for (i = 1; i < unsorted.size(); ++i) {
        auto elementToBeSorted = unsorted.at(i);
        for (j = i-1; j >= 0 && unsorted.at(j) > elementToBeSorted; --j){
           unsorted.at(j+1) = unsorted.at(j);
        }
        unsorted.at(j+1) = elementToBeSorted;
    }
  }

private:

  template<typename T>
  void sort(std::vector<T> &unsorted, int firstIndex, int lastIndex)
  {
    //Determinação do pivô
    auto pivot = unsorted.at((firstIndex+lastIndex)/2);

    //Particionamento
    int leftPointer = firstIndex;
    int rightPointer = lastIndex;

    while(leftPointer < rightPointer)
    {
      while(unsorted.at(leftPointer) < pivot && leftPointer<lastIndex)
      {
        leftPointer = leftPointer + 1;
      }
      while (unsorted.at(rightPointer) > pivot && rightPointer>firstIndex)
      {
        rightPointer = rightPointer - 1;
      }
      if(leftPointer < rightPointer)
      {
        std::swap(unsorted.at(leftPointer), unsorted.at(rightPointer));
        leftPointer = leftPointer + 1;
        rightPointer = rightPointer - 1;
      }
    }

    //Ordenação das sublistas recursivamente
    if(firstIndex < rightPointer)
    {
      sort(unsorted, firstIndex, rightPointer);
    }
    if(leftPointer < lastIndex)
    {
      sort(unsorted, leftPointer+1, lastIndex);
    }
  }

};

#endif // QUICKSORT_H_INCLUDED
