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
#include <chrono>
#include <time.h>

typedef std::chrono::high_resolution_clock Time;

class InsertionSort
{
public:
  long long int comparisons;
  long long int copies;
  double executionTime;

  InsertionSort() {};
  ~InsertionSort() {};

  template<typename T>
  void sort(std::vector<T> &unsorted)
  {
    sort(unsorted, 0, unsorted.size() - 1);
  }

  template<typename T>
  void sort(std::vector<T> &unsorted, int firstIndex, int lastIndex)
  {
    this->comparisons = 0;
    this->copies = 0;
    this->executionTime = 0.0;

    Time::time_point t1 = Time::now(); // Tempo inicial de execução

    /*
     * Consideramos que o primeiro número do array ja está ordenado.
     * Portanto, começamos iterando pelo segundo número
     */
    for (int i = firstIndex + 1; i <= lastIndex; i++)
    {
      auto elementToBeSorted = unsorted.at(i);
      copies++;

      // Indice para acessar elementos já ordenados
      int j = i - 1;
      copies++;

      comparisons++;
      while (j >= 0 && unsorted.at(firstIndex + j) > elementToBeSorted)
      {
        comparisons++;
        // Arredamos uma posição para a direita
        unsorted.at(firstIndex + j + 1) = unsorted.at(firstIndex + j);
        j--;
        copies += 2;
      }
      // Inserimos o número
      unsorted.at(firstIndex + j + 1) = elementToBeSorted;
      copies++;
    }

    Time::time_point t2 = Time::now(); // Tempo final de execução

    // Aqui calcula-se o tempo total de execução para o algoritmo
    this->executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    // Nanosegundos para segundos
    this->executionTime = this->executionTime/1000000000;
  }
};

#endif // INSERTIONSORT_H_INCLUDED
