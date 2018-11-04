/**
 * @file    BTree.hpp
 * @author  Diego Paiva e Silva
 * @date    04/11/2018
 *
 */

#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include "BNode.hpp"
#include "../../../algorithms/sorting/InsertionSort.hpp"

class BTree
{
public:
  int order;
  BNode *root;
  InsertionSort *sorter;

  BTree(int order)
  {
    this->order = order;
    this->root = nullptr;
    this->sorter = new InsertionSort();
  };

  ~BTree() {};

  BNode* insert(int key)
  {
    return insert(key, root);
  }

private:
  BNode* insert(int key, BNode *&node)
  {
    if (node == nullptr)
    {
      return new BNode(order, key);
    }
    else if (!node->hasMaxKeysAmount())
    {
      node->keys.push_back(key);
      sorter->sort(node->keys);

      if (node->hasOverflow())
      {

      }
    }

    return node;
  }

};

#endif // BTREE_H_INCLUDED
