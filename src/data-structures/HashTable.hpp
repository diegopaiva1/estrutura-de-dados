/**
 * @file    HashTable.hpp
 * @author  Diego Paiva e Silva
 * @date    29/08/2018
 *
 */

#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>
#include <climits> // INT_MIN

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
    auto list = this->data.at(hash(data));
    for (auto i = list.begin(); i != list.end(); i++)
    {
      if(*i == data)
      {
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
