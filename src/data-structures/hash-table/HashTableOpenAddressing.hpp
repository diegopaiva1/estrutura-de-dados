#ifndef HASHTABLEOPENADDRESSING_H_INCLUDED
#define HASHTABLEOPENADDRESSING_H_INCLUDED

#include <iostream>
#include <vector>

#define PRIME 997

class HashTableOpenAddressing
{
public:
  std::vector<int> data;
  int size;

  HashTableOpenAddressing() {};
  ~HashTableOpenAddressing() {};

  HashTableOpenAddressing(std::string algorithm)
  {
    this->algorithm = algorithm;
  }

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

  int insert(int data)
  {
    int position = hash(data);
    int collisions = 0;
    int comparisons = 0;

    comparisons++;
    while (this->data.at(position) != NULL && collisions != this->size)
    {
      comparisons++;
      collisions++;
      position = calculatePositionFromAlgorithm(data, collisions);
    }

    comparisons++;
    if (this->data.at(position) == NULL)
    {
      this->data.at(position) = data;
    }
    else
    {
      throw "Tabela lotada!";
    }

    return comparisons;
  }

  void remove(int data)
  {
    int position = hash(data);
    int collisions = 0;

    while (this->data.at(position) != data && collisions != this->size)
    {
      collisions++;
      position = calculatePositionFromAlgorithm(data, collisions);
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
      position = calculatePositionFromAlgorithm(data, collisions);
    }
    // Total de comparações
    return collisions + 1;
  }

private:
  std::string algorithm;

  int calculatePositionFromAlgorithm(int data, int collisions)
  {
    int position;
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
      position = hash(hash(data) + collisions * rehash(data));
    }
    return position;
  }

  int hash(int data)
  {
    // Método da divisão
    return data % this->size;
  }

  int rehash(int data)
  {
    return PRIME - (data % PRIME);
  }
};

#endif // HASHTABLEOPENADRESSING_H_INCLUDED
