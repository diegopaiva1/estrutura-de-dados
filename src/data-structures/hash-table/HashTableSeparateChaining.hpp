/**
 * @file    HashTableSeparateChainingSeparateChaining.hpp
 * @author  Diego Paiva e Silva
 * @date    29/08/2018
 *
 * Esta classe implementa uma Tabela Hash para valores inteiros com encadeamento separado para
 * tratamento de colisões.
 * A função de hash utilizada é h(k) = k mod m, tal que k = dado a ser inserido e m = tamanho da tabela.
 * Esta função de hash é também conhecida por método da divisão.
 */

#ifndef HASHTABLESEPARATECHAINING_H_INCLUDED
#define HASHTABLESEPARATECHAINING_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>

class HashTableSeparateChaining
{
public:
  std::vector<std::list<int>> data;
  int size;

  HashTableSeparateChaining() {};
  ~HashTableSeparateChaining() {};

  HashTableSeparateChaining(int size, float loadFactor = 0.75)
  {
    // Calculamos o tamanho da tabela
    this->size = (int) size/loadFactor;

    // Alocamos espaço suficiente para os dados de entrada
    this->data.resize(this->size);
  }

  HashTableSeparateChaining(std::vector<int> data, float loadFactor = 0.75)
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

  int insert(int data)
  {
    this->data.at(hash(data)).push_back(data);
    // Retornando o total de comparações para fazer a inserção, neste caso é sempre 0
    return 0;
  }

  int get(int data)
  {
    // Encontramos a lista do elemento a ser buscado
    auto list = this->data.at(hash(data));

    for (auto i = list.begin(); i != list.end(); i++)
    {
      if (*i == data)
      {
        return *i;
      }
    }

    throw "Dado inexistente!";
  }

  void remove(int data)
  {
    if(dataExists(data))
    {
      this->data.at(hash(data)).remove(data);
    }
    else
    {
      throw "Impossível remover - Dado não existe";
    }
  }

private:
  int hash(int data)
  {
    // Método da divisão
    return data % this->size;
  }

  bool dataExists(int data)
  {
    return this->data.at(hash(data)).size() != 0;
  }
};

#endif // HASHTABLESEPARATECHAINING_H_INCLUDED
