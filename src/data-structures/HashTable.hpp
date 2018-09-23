/**
 * @file    HashTable.hpp
 * @author  Diego Paiva e Silva
 * @date    29/08/2018
 *
 * Esta classe implementa uma Tabela Hash para valores inteiros com encadeamento separado para
 * tratamento de colisões.
 * A função de hash utilizada é h(k) = k mod m, tal que k = dado a ser inserido e m = tamanho da tabela.
 * Esta função de hash é também conhecida por método da divisão.
 */

#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>

class HashTable
{
public:
  HashTable() {};
  ~HashTable() {};

  HashTable(std::vector<int> data, float loadFactor)
  {
    // Calculamos o tamanho da tabela
    this->size = (int) data.size()/loadFactor;

    // Alocamos espaço suficiente para os dados de entrada
    this->data.resize(this->size);

    for (unsigned int i = 0; i < data.size(); i++)
    {
      insert(data.at(i));
    }
  }

  void insert(int data)
  {
    this->data.at(hash(data)).push_back(data);
  }

  void remove(int data)
  {
    this->data.at(hash(data)).remove(data);
  }

  int get(int data)
  {
    // Encontramos a lista do elemento a ser buscado
    auto list = this->data.at(hash(data));
    int comparisons = 0;

    for (auto i = list.begin(); i != list.end(); i++)
    {
      comparisons++;
      if (*i == data)
      {
        std::cout << "Comparações: " << comparisons << std::endl;
        return *i;
      }
    }

    throw "Dado inexistente!";
  }

private:
  std::vector<std::list<int>> data;
  int size;

  int hash(int data)
  {
    // Método da divisão
    return data % this->size;
  }
};

#endif // HASHTABLE_H_INCLUDED
