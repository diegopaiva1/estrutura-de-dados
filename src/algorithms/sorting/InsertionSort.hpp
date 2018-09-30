/**
 * @file    InsertionSort.hpp
 * @author  Diego Paiva e Silva
 * @date    08/08/2018
 *
 * O algoritmo InsertionSort é um algoritmo O(n²) estável para ordenação de elementos de uma lista.
 * Esta classe implementa o algoritmo para ordenação de um array de elementos de QUALQUER tipo.
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
#include <vector>

class InsertionSort
{
public:
  InsertionSort() {};
  ~InsertionSort() {};

  template<typename T>
  void sort(std::vector<T> &unsorted){
    sort(unsorted, 0, unsorted.size() - 1);
  }

  template<typename T>
  void sort(std::vector<T> &unsorted, int firstIndex, int lastIndex)
  {
    // Consideramos que o primeiro número do array ja está ordenado
    int amountOfSortedNumbers = 1;

    // Portanto, começamos iterando pelo segundo número
    for (int i = firstIndex+1; i <= lastIndex; i++)
    {
      auto elementToBeSorted = unsorted.at(i);

      // Indice para acessar elementos já ordenados
      int j = amountOfSortedNumbers - 1;

      while(j >= 0 && unsorted.at(firstIndex+j) > elementToBeSorted)
      {
        // Arredamos uma posição para a direita
        unsorted.at(firstIndex+j+1) = unsorted.at(firstIndex+j);
        j--;
      }
      // Inserimos o número
      unsorted.at(firstIndex+j+1) = elementToBeSorted;

      amountOfSortedNumbers++;
    }
  }
};

#endif // INSERTIONSORT_H_INCLUDED
