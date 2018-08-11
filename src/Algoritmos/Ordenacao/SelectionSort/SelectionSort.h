/**
 * @file    SelectionSort.h
 * @author  Diego Paiva e Silva
 * @date    11/08/2018
 */

#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED

#include <iostream>

#include "../../../Utils/ArrayUtils/ArrayUtils.h"

class SelectionSort
{
public:
  SelectionSort() {};
  ~SelectionSort() {};
  void sort(int unsortedNumbers[], int size);
};

#endif // SELECTIONSORT_H_INCLUDED
