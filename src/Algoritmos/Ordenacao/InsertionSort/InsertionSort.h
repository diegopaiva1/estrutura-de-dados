/**
 * @file    InsertionSort.h
 * @author  Diego Paiva e Silva
 * @date    08/08/2018
 * @version 1.0
 *
 * Classe que implementa o algoritmo InsertionSort para ordenação de um array de inteiros.
 * Complexidade:
 *  => Melhor caso: n
 *  => Caso médio: n²
 *  => Pior caso: n²
 * O algoritmo é estável.
 */

#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED

#include <iostream>

class InsertionSort
{
public:
  InsertionSort() {};
  ~InsertionSort() {};
  void sort(int *unsortedNumbers, int size);
};

#endif // INSERTIONSORT_H_INCLUDED
