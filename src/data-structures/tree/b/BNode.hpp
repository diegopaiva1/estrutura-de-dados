/**
 * @file    BNode.hpp
 * @author  Diego Paiva e Silva
 * @date    04/11/2018
 *
 */

#ifndef BNODE_H_INCLUDED
#define BNODE_H_INCLUDED

#include <vector>
#include "../../../algorithms/sorting/InsertionSort.hpp"

class BNode
{
public:
  unsigned int order;
  bool isLeaf;
  std::vector<int> keys;
  std::vector<BNode *> children;
  InsertionSort *sorter;

  BNode(int order, bool isLeaf)
  {
    this->order = order;
    this->isLeaf = isLeaf;
    this->children.reserve(order + 1);
    this->sorter = new InsertionSort();

    // Armazena até 'order' chaves (um espaço é reservado para overflow)
    keys.reserve(order);
  };

  ~BNode() {};

  void insert(int key)
  {
    if (this->isLeaf)
    {
      keys.push_back(key);
      sorter->sort(keys);
      return;
    }

    BNode *child;

    for (int i = 0; i < keys.size(); i++)
    {
      if (key < keys.at(i))
        child = children.at(i);
      else
        child = children.at(i + 1);
    }

    if (child->hasMaxKeysAmount())
    {
      // Aqui rola o overflow
      child->insert(key);

      split(child);
      return;
    }

    child->insert(key);
  }

  bool hasMaxKeysAmount()
  {
    return keys.size() == order - 1;
  }

  void split(BNode *&splitted)
  {
    BNode *node = new BNode(splitted->order, splitted->isLeaf);

    // Copy right half of the keys from splitted-node to the new node
    for (int i = splitted->keys.capacity() - 1; i > splitted->keys.capacity()/2; i--)
    {
      node->insert(splitted->keys.at(i));
      splitted->keys.erase(splitted->keys.begin() + i);
    }

    if (!splitted->isLeaf)
    {
      // Copy right half of the child pointers from splitted-node to the new node
      for (int i = splitted->children.size()/2; i < splitted->children.size(); i++)
        node->children.push_back(splitted->children.at(i));
    }

    this->children.push_back(node);

    this->keys.push_back(splitted->keys.at(order/2));
    splitted->keys.erase(splitted->keys.begin() + order/2);
  }
};

#endif // BNODE_H_INCLUDED
