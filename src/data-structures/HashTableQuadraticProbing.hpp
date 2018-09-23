#ifndef HASHTABLEQUADRATICPROBING_H_INCLUDED
#define HASHTABLEQUADRATICPROBING_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>

class HashTableQuadraticProbing
{
public:
  HashTableQuadraticProbing() {};
  ~HashTableQuadraticProbing() {};

  HashTableQuadraticProbing(std::vector<int> data, float loadFactor)
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
    int position = hash(data);
    int collisions = 0;
    while(this->data.at(position)!=NULL && collisions!=this->size){
        collisions++;
        position = hash(hash(data)+(collisions*collisions));
    }
    if(this->data.at(position)==NULL){
        auto i = this->data.begin() + position;
        this->data.erase(i);
        this->data.insert(i, data);
    }
    else{
        throw "Tabela lotada!";
    }
  }

  void remove(int data)
  {
    int position = hash(data);
    int collisions = 0;
    while(this->data.at(position)!=data  && collisions!=this->size){
        collisions++;
        position = hash(hash(data)+(collisions*collisions));
    }
    if(this->data.at(position)==data){
        auto i = this->data.begin() + position;
        this->data.erase(i);
    }
    else{
        throw "Dado inexistente!";
    }
  }

  int get(int data)
  {
    int position = hash(data);
    int collisions = 0;
    while(this->data.at(position)!=data  && collisions!=this->size){
        collisions++;
        position = hash(hash(data)+(collisions*collisions));
    }
    if(this->data.at(position)==data){
        return this->data.at(position);
    }

    throw "Dado inexistente!";
  }

  void imprimir()
  {
    for(auto i=this->data.begin(); i!=this->data.end(); i++){
        std:: cout << *i << "   ";
    }
    std:: cout << std::endl;
  }

private:
  std::vector<int> data;
  int size;

  int hash(int data)
  {
    // Método da divisão
    return data % this->size;
  }
};

#endif // HASHTABLE_H_INCLUDED