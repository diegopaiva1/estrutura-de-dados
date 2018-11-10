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
    keys.push_back(key);
    sorter->sort(keys);
  }

  bool hasOverflow()
  {
    return keys.size() == order;
  }

  void split(BNode *&splitted)
  {
    BNode *node = new BNode(splitted->order, splitted->isLeaf);

    for (int i = splitted->keys.size()/2; i < splitted->keys.size(); i++)
      node->insert(splitted->keys.at(i));

    if (!splitted->isLeaf)
    {
      for (int i = 0; i < order; i++)
        node->children.push_back(splitted->children.at(i + order));
    }

    this->children.push_back(node);

  }
};

#endif // BNODE_H_INCLUDED
