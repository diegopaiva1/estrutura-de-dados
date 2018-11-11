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

  int get(int key)
  {
    BNode *node = root;

    while (node != nullptr)
    {
      int index = 0;

      while (index < node->keys.size() && key > node->keys.at(index))
        index++;

      if (index < node->keys.size() && key == node->keys.at(index))
        return node->keys.at(index);

      node = node->children.at(index);
    }

    // Se chegou até aqui, todas as possibilidades foram exploradas
    throw "Chave inexistente na árvore B";
  }
};

#endif // BTREE_H_INCLUDED
