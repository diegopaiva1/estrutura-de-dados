/**
 * @file    MergeSort.h
 * @author  Diego Paiva e Silva
 * @date    15/08/2018
 *
 * O algoritmo MergeSort é um algoritmo O(nlogn) instável que utiliza o paradigma divisão e conquista
 * para ordenação de elementos de uma lista.
 * Esta classe implementa o algoritmo para ordenação de um array de inteiros.
 * A estratégia consiste em:
 * 1. Dada uma lista de N números, dividi-la até que obtenham-se N listas de tamanho 1 (recursivamente);
 * 2. Partindo da ideia de que uma lista com um único elemento já está naturalmente ordenada,
 *    basta realizar, duas a duas, a união ordenada das listas resultantes da divisão;
 * 3. A cada passo o algoritmo gera novas listas ordenadas com mais elementos (volta da recursão);
 * 4. Ir realizando a união ordenada das listas até que se obtenha uma única lista ordenada com todos os elementos.
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
