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

class HashTable
{
public:
  HashTable() {};
  ~HashTable() {};

  std::vector<std::list<int>> data;

  HashTable(std::vector<int> data)
  {
    this->data.resize(23);
    for (unsigned int i = 0; i < data.size(); i++)
    {
      insert(data.at(i));
    }
  }

  void insert(int data)
  {
    int position = hashIt(data);
    this->data.at(position).push_back(data);
  }

  int hashIt(int data)
  {
    return data % 23;
  }

  void remove(int data)
  {
    this->data.erase(this->data.begin() + hashIt(data));
  }

};

#endif // HASHTABLE_H_INCLUDED
