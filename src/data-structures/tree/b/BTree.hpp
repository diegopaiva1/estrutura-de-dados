/**
 * @file    BTree.hpp
 * @author  Diego Paiva e Silva
 * @date    04/11/2018
 *
 */

#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include "BNode.hpp"

class BTree
{
public:
  unsigned int order;
  BNode *root;

  BTree(int order)
  {
    this->order = order;
    this->root = nullptr;
  };

  ~BTree() {};

  void insert(int key)
  {
    if (root == nullptr)
    {
      root = new BNode(order, true);
      root->insert(key);
    }
    else if (root->hasMaxKeysAmount())
    {
      // Overflow ocorre nesta inserção
      root->insert(key);

      BNode *node = new BNode(order, false);
      node->children.push_back(root);
      root = node;
      node->split(node->children.at(0));
    }
    else
    {
      root->insert(key);
    }
  }
};

#endif // BTREE_H_INCLUDED
