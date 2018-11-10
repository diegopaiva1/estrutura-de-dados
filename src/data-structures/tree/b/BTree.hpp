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
      root->keys.push_back(key);
    }
    else
    {
      if (!root->hasOverflow())
      {
        root->insert(key);
      }
      else
      {
        BNode *node = new BNode(order, false);

        // Raíz passa a ser filha do novo nó
        node->children.push_back(root);

        node->split(root);

        int i = 0;
        if (node->keys.at(0) < key)
          i++;

        node->children.at(i)->insert(key);

        // Change root
        root = node;
      }
    }
  }
};

#endif // BTREE_H_INCLUDED
