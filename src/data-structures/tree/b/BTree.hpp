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
  long long int comparisons;
  long long int copies;

  BTree(int maxDegree)
  {
    this->maxDegree = maxDegree;
    this->root = nullptr;
  };

  ~BTree() {};

  void insert(int key)
  {
    comparisons++;
    if (root == nullptr)
    {
      copies++;
      root = new BNode(maxDegree, true);
      root->insert(key, comparisons, copies);
    }
    else
    {
      root->insert(key, comparisons, copies);

      comparisons++;
      if (root->hasOverflow())
      {
        copies += 3;
        // Crescimento bottom-up: atual raíz passa a ser filho de um novo nó
        BNode *node = new BNode(maxDegree, false);
        node->children.at(0) = root;
        root = node;
        node->split(node->children.at(0), 0, comparisons, copies);
      }
    }
  }

  int get(int key)
  {
    copies++;
    BNode *node = root;

    while (node != nullptr)
    {
      comparisons++;
      copies++;
      unsigned int index = 0;


      while (index < node->keys.size() && key > node->keys.at(index))
      {
        comparisons++;
        copies++;
        index++;
      }

      comparisons++;
      if (index < node->keys.size() && key == node->keys.at(index))
        return node->keys.at(index);

      copies++;
      node = node->children.at(index);
    }

    // Se chegou até aqui, todas as possibilidades foram exploradas
    // throw "Chave inexistente na árvore B";
    return -1;
  }
};

#endif // BTREE_H_INCLUDED
