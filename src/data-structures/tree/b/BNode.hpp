/**
 * @file    BNode.hpp
 * @author  Diego Paiva e Silva
 * @date    04/11/2018
 *
 */

#ifndef BNODE_H_INCLUDED
#define BNODE_H_INCLUDED

#include <iostream>
#include <vector>

class BNode
{
public:
  int order;
  std::vector<int> keys;
  std::vector<BNode *> children;

  BNode(int order, int key)
  {
    this->order = order;
    this->children.resize(order + 1);

    // Armazena até 'order' chaves (um espaço é reservado para overflow)
    keys.reserve(order);
    keys.push_back(key);
  };

  ~BNode() {};

  bool hasMaxKeysAmount()
  {
    int keysAmount = 0;
    for (auto key : keys)
    {
      if (key != NULL)
      {
        keysAmount++;
      }
    }

    return keysAmount == order;
  }

  bool hasOverflow()
  {
    return keys.size() == order;
  }
};

#endif // BNODE_H_INCLUDED
