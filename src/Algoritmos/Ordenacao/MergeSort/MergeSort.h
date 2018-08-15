/**
 * @file    MergeSort.h
 * @author  Diego Paiva e Silva
 * @date    15/08/2018
 *
 */

#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <iostream>

class MergeSort
{
public:
  MergeSort() {};
  ~MergeSort() {};
  void mergeTwoSortedLists(int sortedList1[], int size1,
                           int sortedList2[], int size2,
                           int mergedList[]);
  void sort(int unsortedNumbers[], int size);
};

#endif // MERGESORT_H_INCLUDED
