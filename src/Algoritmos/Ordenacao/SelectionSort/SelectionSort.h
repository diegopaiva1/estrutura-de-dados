/**
 * @file    SelectionSort.h
 * @author  Diego Paiva e Silva
 * @date    11/08/2018
 */

#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED

#include <iostream>

class SelectionSort
{
private:
  int findMinimumValue(int array[], int size, int index);
  int findMinimumValueIndex(int array[], int size, int index);
  void swapValues(int array[], int firstIndex, int secondIndex);
public:
  SelectionSort() {};
  ~SelectionSort() {};
  void sort(int unsortedNumbers[], int size);
};

#endif // SELECTIONSORT_H_INCLUDED
