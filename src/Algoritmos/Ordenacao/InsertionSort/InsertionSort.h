/**
 * @file    InsertionSort.h
 * @author  Diego Paiva e Silva
 * @date    08/08/2018
 *
 * O algoritmo InsertionSort é um algoritmo O(n²) estável para ordenação de elementos de uma lista.
 * Esta classe implementa o algoritmo para ordenação de um array de inteiros.
 * A estratégia consiste em:
 * 1. Considerar o primeiro elemento como já ordenado e o supor em uma partição de elementos já ordenados;
 * 2. Percorrer as posições do array, começando pelo segundo elemento (indíce 1);
 * 3. Comparar o elemento atual com os elementos da partição ordenada, da direita para esquerda;
 * 4. Enquanto o elemento da partição ordenada for maior que o elemento a ser ordenado, move-se o elemento
 *    da partição ordenada uma posição à direita;
 * 5. Quando a condição acima não for satisfeita, inserir o elemento não-ordenado na posição vaga.
 */

#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED

#include <iostream>

class InsertionSort
{
public:
  InsertionSort() {};
  ~InsertionSort() {};
  void sort(int unsortedNumbers[], int size);
};

#endif // INSERTIONSORT_H_INCLUDED
