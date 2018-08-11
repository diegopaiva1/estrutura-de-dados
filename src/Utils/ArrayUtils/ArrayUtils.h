/**
 * @file    ArrayUtils.h
 * @author  Diego Paiva e Silva
 * @date    11/08/2018
 */

#ifndef ARRAYUTILS_H_INCLUDED
#define ARRAYUTILS_H_INCLUDED

#include <iostream>

class ArrayUtils
{
public:
  static int findMinimumValueIndex(int array[], int size, int startingIndex);
  static void swapValues(int array[], int firstIndex, int secondIndex);
};

#endif // ARRAYUTILS_H_INCLUDED
