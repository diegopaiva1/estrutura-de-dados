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
      unsigned int index = 0;

      while (index < node->keys.size() && key > node->keys.at(index))
        index++;

      if (index < node->keys.size() && key == node->keys.at(index))
        return node->keys.at(index);

      node = node->children.at(index);
    }

    // Se chegou até aqui, todas as possibilidades foram exploradas
    throw "Chave inexistente na árvore B";
  }

  BNode* getNode(int key)
  {
    BNode *node = root;

    while (node != nullptr)
    {
      unsigned int index = 0;

      while (index < node->keys.size() && key > node->keys.at(index))
        index++;

      if (index < node->keys.size() && key == node->keys.at(index))
        return node;

      node = node->children.at(index);
    }

    throw "Chave inexistente na árvore B";
  }

  void remove(int key)
  {
    BNode *node = getNode(key);
    unsigned int index = 0;
    while (index < node->keys.size() && key > node->keys.at(index))
      index++;
    if (index < node->keys.size() && key == node->keys.at(index))
      if(node->isLeaf)
      {
        node->keys.erase (node->keys.begin()+index);
      }
      else
      {
        BNode* nearest = node->children.at(index+1);
        if(nearest->keys.front()!=NULL)
        {
          std::swap(node->keys.at(index), nearest->keys.front());
        }
        else
        {
          nearest = node->children.at(index);
          std::swap(node->keys.at(index), nearest->keys.back());
        }
        node->keys.erase (node->keys.begin()+index);
      }
      if(node->hasOverflow())
      {
      fixUnderflow(node);
      }
    }

    void fixUnderflow(BNode* &node)
    {

    }
  };

#endif // BTREE_H_INCLUDED
