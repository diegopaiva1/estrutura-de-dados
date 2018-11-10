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
  unsigned int maxDegree;
  BNode *root;

  BTree(int maxDegree)
  {
    this->maxDegree = maxDegree;
    this->root = nullptr;
  };

  ~BTree() {};

  void insert(int key)
  {
    if (root == nullptr)
    {
      root = new BNode(maxDegree, true);
      root->insert(key);
    }
    else
    {
      root->insert(key);

      if (root->hasOverflow())
      {
        // Crescimento bottom-up: atual raíz passa a ser filho de um novo nó
        BNode *node = new BNode(maxDegree, false);
        node->children.at(0) = root;
        root = node;
        node->split(node->children.at(0), 0);
      }
    }
  }
};

#endif // BTREE_H_INCLUDED
