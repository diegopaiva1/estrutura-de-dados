/**
 * @file    MergeSort.h
 * @author  Diego Paiva e Silva
 * @date    15/08/2018
 *
 */

#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <iostream>

#include "../../../Utils/ArrayUtils/ArrayUtils.h"

class MergeSort
{
private:
  bool sizeIsEven(int size);
  void generateSortedArrayByMergingTwoSortedArrays(int sorted1[], int size1,
                                                   int sorted2[], int size2,
                                                   int merged[]);
  bool arrayWasFullyCovered(int iterator, int size);
public:
  MergeSort() {};
  ~MergeSort() {};
  void sort(int unsortedNumbers[], int size);
};

#endif // MERGESORT_H_INCLUDED
