#ifndef DEPUTYHASHTABLE_H_INCLUDED
#define DEPUTYHASHTABLE_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>
#include <string.h>

#include "Deputy.hpp"

class DeputyHashTable
{
public:
  std::vector<std::list<Deputy>> deputies;
  int size;

  DeputyHashTable() {};
  ~DeputyHashTable() {};

  DeputyHashTable(int size, float loadFactor = 0.75)
  {
    // Calculamos o tamanho da tabela
    this->size = (int) size/loadFactor;

    // Alocamos espaço suficiente para os dados de entrada
    this->deputies.resize(this->size);
  }

  DeputyHashTable(std::vector<Deputy> deputies, float loadFactor = 0.75)
  {
    // Calculamos o tamanho da tabela
    this->size = (int) deputies.size()/loadFactor;

    // Alocamos espaço suficiente para os dados de entrada
    this->deputies.resize(this->size);

    for (unsigned int i = 0; i < deputies.size(); i++)
    {
      insert(deputies.at(i));
    }
  }

  void insert(Deputy deputy)
  {
    this->deputies.at(hash(deputy.name)).push_back(deputy);
  }

  Deputy get(std::string deputyName)
  {
    // Encontramos a lista do elemento a ser buscado
    auto list = this->deputies.at(hash(deputyName));

    for (auto i = list.begin(); i != list.end(); i++)
    {
      Deputy d = *i;
      if (d.name == deputyName)
      {
        return d;
      }
    }

    throw "Deputado não existe";
  }

private:
  int hash(std::string s)
  {
    char ch[s.length()+1];
    // copying the contents of the
    // string to char array
    strcpy(ch, s.c_str());

    int i, sum;

    for (sum=0, i=0; i < s.length(); i++)
      sum += ch[i];

    return sum % size;
  }
};

#endif // DEPUTYHASHTABLE_H_INCLUDED
