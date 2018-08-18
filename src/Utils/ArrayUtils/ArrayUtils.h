/**
 * @file    ArrayUtils.h
 * @author  Diego Paiva e Silva
 * @date    11/08/2018
 *
 * A classe ArrayUtils implementa algumas operações frequentemente utilizadas
 * quando manipula-se arrays, como por exemplo: troca de posição entre dois valores,
 * contar o número total de elementos, etc.
 */

#ifndef ARRAYUTILS_H_INCLUDED
#define ARRAYUTILS_H_INCLUDED

#include <iostream>

class ArrayUtils
{
public:
  static int findMinimumValueIndex(int array[], int size, int startingIndex);
  static void swapValues(int array[], int firstIndex, int secondIndex);
  static void copyArrayValuesIntoAnotherArray(int arrayToCopyValuesFrom[], int arrayToReceiveValues[],
                                              int startingIndex, int lastIndex);
};

#endif // ARRAYUTILS_H_INCLUDED
