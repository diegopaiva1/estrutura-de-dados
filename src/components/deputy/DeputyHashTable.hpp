#ifndef DEPUTYHASHTABLE_H_INCLUDED
#define DEPUTYHASHTABLE_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>
#include <string.h>

#include "Deputy.hpp"
#include "Spent.hpp"
#include "../../algorithms/sorting/QuickSort.hpp"

class DeputyHashTable
{
public:
  std::vector<std::list<Deputy>> deputies;
  int size;

  DeputyHashTable() {};
  ~DeputyHashTable() {};

  DeputyHashTable(int size, float loadFactor = 0.75, std::string keyType = "nome")
  {
    this->keyType = keyType;

    // Calculamos o tamanho da tabela
    this->size = (int) size/loadFactor;

    // Alocamos espaço suficiente para os dados de entrada
    this->deputies.resize(this->size);
  }

  DeputyHashTable(std::vector<Deputy> deputies, float loadFactor = 0.75, std::string keyType = "nome")
  {
    this->keyType = keyType;

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
    if(this->keyType == "nome")
    {
      this->deputies.at(hash(deputy.name)).push_back(deputy);
    }
    else if(this->keyType == "partido")
    {
      this->deputies.at(hash(deputy.party)).push_back(deputy);
    }
  }

  void highestsSpent(int n)
  {
    this->calculateSpent();
    QuickSort *quickSort = new QuickSort();
    quickSort->sort(this->spent);
    for(int i=0; i<n; i++)
    {
      std::cout << this->spent.at(this->spent.size()-1-i).name << ": " << this->spent.at(this->spent.size()-1-i).spent << std::endl;
    }
  }

  void lowestsSpent(int n)
  {
    this->calculateSpent();
    QuickSort *quickSort = new QuickSort();
    quickSort->sort(this->spent);
    for(int i=0; i<n; i++)
    {
      std::cout << this->spent.at(i).name << ": " << this->spent.at(i).spent << std::endl;
    }
  }

private:
  std::vector<Spent> spent;
  std::string keyType;

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

  void calculateSpent()
  {
    for(int i=0; i<deputies.size(); i++)
    {
      // Encontramos a lista de gastos do deputado ou partido
      auto list = this->deputies.at(i);
      int sum = 0;
      Spent *s = new Spent();
      for (auto k = list.begin(); k != list.end(); k++)
      {
        auto deputy = *k;
        if(this->keyType == "nome")
        {
          s->name = deputy.name;
        }
        else if(this->keyType == "partido")
        {
          s->name = deputy.party;
        }
        break;
      }
      for (auto j = list.begin(); j != list.end(); j++)
      {
        Deputy d = *j;
        sum += d.receiptValue;
      }
      s->spent  = sum;
      this->spent.push_back(*s);
    }
  }
};

#endif // DEPUTYHASHTABLE_H_INCLUDED
