#ifndef HASHTABLECOALESCEDCHAINING_H_INCLUDED
#define HASHTABLECOALESCEDCHAINING_H_INCLUDED

#include <iostream>
#include <vector>

class HashTableCoalescedChaining
{
public:
  std::vector<int> data;
  std::vector<int> pointer;
  int size;

  HashTableCoalescedChaining() {};
  ~HashTableCoalescedChaining() {};

  HashTableCoalescedChaining(std::vector<int> data, float loadFactor)
  {
    // Calculamos o tamanho da tabela
    this->size = (int) data.size()/loadFactor;

    // Alocamos espaço suficiente para os dados de entrada
    this->data.resize(this->size);
    this->pointer.resize(this->size);

    for (unsigned int i = 0; i < data.size(); i++)
    {
      insert(data.at(i));
    }
  }

  HashTableCoalescedChaining(int size)
  {
    // Tamanho da tabela
    this->size = size;

    // Alocamos espaço suficiente para os dados de entrada
    this->data.resize(this->size);
    this->pointer.resize(this->size);
  }

  void insert(int data)
  {
    int position = hash(data);
    int collisions = 0;

    while (this->data.at(position) != NULL && collisions != this->size)
    {
      position = (this->size - 1) - collisions;
      collisions++;
    }

    if (this->data.at(position) == NULL)
    {
      this->data.at(position) = data;

      if (collisions != 0)
      {
        int pointerPosition = hash(data);

        while (this->pointer.at(pointerPosition) != NULL)
        {
          pointerPosition = this->pointer.at(pointerPosition);
        }

        if (this->pointer.at(pointerPosition) == NULL)
        {
          this->pointer.at(pointerPosition) = position;
        }
      }
    }
    else
    {
      throw "Tabela lotada!";
    }
  }

  void remove(int data)
  {
    int position = hash(data);
    int previousPosition;
    int collisions = 0;

    while (this->data.at(position) != data && collisions != this->size)
    {
      collisions++;
      previousPosition = position;
      position = this->pointer.at(position);
    }

    if (this->data.at(position) == data)
    {
      if (collisions != 0)
      {
        this->pointer.at(previousPosition) = this->pointer.at(position);
      }
      this->data.at(position) = NULL;
      this->pointer.at(position) = NULL;
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
      position = this->pointer.at(position);
    }

    // Total de comparações
    return collisions + 1;
  }

private:
  int hash(int data)
  {
    // Método da divisão
    return data % this->size;
  }
};

#endif // HASHTABLECOALESCEDCHAINING_H_INCLUDED
