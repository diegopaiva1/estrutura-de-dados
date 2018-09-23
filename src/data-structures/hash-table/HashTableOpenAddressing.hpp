#ifndef HASHTABLEOPENADDRESSING_H_INCLUDED
#define HASHTABLEOPENADDRESSING_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>

class HashTableOpenAddressing
{
public:
  HashTableOpenAddressing() {};
  ~HashTableOpenAddressing() {};

  HashTableOpenAddressing(std::vector<int> data, float loadFactor, std::string algorithm)
  {
    // Calculamos o tamanho da tabela
    this->size = (int) data.size()/loadFactor;

    // Define o tipo de endereçamento
    this->algorithm = algorithm;

    // Alocamos espaço suficiente para os dados de entrada
    this->data.resize(this->size);

    for (unsigned int i = 0; i < data.size(); i++)
    {
      insert(data.at(i));
    }
  }

  HashTableOpenAddressing(int size, std::string algorithm)
  {
    // Tamanho da tabela
    this->size = size;

    // Define o tipo de endereçamento
    this->algorithm = algorithm;

    // Alocamos espaço suficiente para os dados de entrada
    this->data.resize(this->size);
  }

  void insert(int data)
  {
    int position = hash(data);
    int collisions = 0;

    while (this->data.at(position) != NULL && collisions != this->size)
    {
      collisions++;
      if (this->algorithm == "Linear Probing")
      {
        position = hash(hash(data) + collisions);
      }
      else if (this->algorithm == "Quadratic Probing")
      {
        position = hash(hash(data) + (collisions * collisions));
      }
      else if (this->algorithm == "Double Hashing")
      {
        position = hash(hash(data) + (collisions * hash(data)));
      }
    }

    if (this->data.at(position) == NULL)
    {
      this->data.at(position) = data;
    }
    else
    {
      throw "Tabela lotada!";
    }
  }

  void remove(int data)
  {
    int position = hash(data);
    int collisions = 0;

    while (this->data.at(position) != data && collisions != this->size)
    {
      collisions++;
      if (this->algorithm == "Linear Probing")
      {
        position = hash(hash(data) + collisions);
      }
      else if (this->algorithm == "Quadratic Probing")
      {
        position = hash(hash(data) + (collisions * collisions));
      }
      else if (this->algorithm == "Double Hashing")
      {
        position = hash(hash(data) + (collisions * hash(data)));
      }
    }
    if (this->data.at(position) == data)
    {
      this->data.at(position) = NULL;
    }
    else
    {
      throw "Dado inexistente!";
    }
  }

  int get(int data)
  {
    int position = hash(data);
    int collisions = 0;

    while (this->data.at(position) != data && collisions != this->size)
    {
      collisions++;
      if (this->algorithm == "Linear Probing")
      {
        position = hash(hash(data) + collisions);
      }
      else if (this->algorithm == "Quadratic Probing")
      {
        position = hash(hash(data) + (collisions * collisions));
      }
      else if (this->algorithm == "Double Hashing")
      {
        position = hash(hash(data) + (collisions * hash(data)));
      }
    }

    if (this->data.at(position) == data)
    {
      return this->data.at(position);
    }

    throw "Dado inexistente!";
  }

private:
  std::vector<int> data;
  std::string algorithm;
  int size;

  int hash(int data)
  {
    // Método da divisão
    return data % this->size;
  }
};

#endif // HASHTABLEOPENADRESSING_H_INCLUDED
