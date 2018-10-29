#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#include "AVLNode.hpp"

class AVLTree
{
public:
  AVLNode *root;

  AVLTree(AVLNode *root)
  {
    this->root = root;
  };

  AVLTree()
  {
    root = nullptr;
  };

  ~AVLTree() {};

  void insert(int value)
  {
    if (!hasRoot())
    {
      root = new AVLNode(value);
    }
    else
    {
      auto node = root;

      while (node != nullptr)
      {
        if (value < node->value)
        {
          node = node->left;
        }
        else
        {
          node = node->right;
        }
      }

      node = new AVLNode(value);
    }
  }

  AVLNode* get(int value)
  {
    auto node = root;

    while (node != nullptr)
    {
      if (value == node->value)
      {
        return node;
      }
      else if (value < node->value)
      {
        node = node->left;
      }
      else if (value > node->value)
      {
        node = node->right;
      }
    }

    throw "Valor não existente na árvore AVL";
  }

private:
  bool hasRoot()
  {
    return root != nullptr;
  }
};

#endif // AVLTREE_H_INCLUDED
