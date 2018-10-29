#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#include "AVLNode.hpp"

class AVLTree
{
public:
  AVLNode *root;

  AVLTree()
  {
    root = nullptr;
  };

  ~AVLTree() {};

  int height()
  {
    return root->height(root);
  }

  AVLNode* insert(int value)
  {
    return insert(value, root);
  }

  AVLNode* get(int value)
  {
    return get(value, root);
  }

private:
  AVLNode* insert(int value, AVLNode* node)
  {
    if (node == nullptr)
    {
      return new AVLNode(value);
    }
    else
    {
      if (value < node->value)
      {
        node->left = insert(value, node->left);
      }
      else
      {
        node->right = insert(value, node->right);
      }
    }

    return node;
  }

  AVLNode* rotateRight(AVLNode *node)
  {
    AVLNode *rotated = node->right;
    node->right = rotated->left;
    rotated->left = node;
    return rotated;
  }

  AVLNode* rotateLeft(AVLNode *node)
  {
    AVLNode *rotated = node->left;
    node->left = rotated->right;
    rotated->right = node;
    return rotated;
  }

  AVLNode* get(int value, AVLNode* node)
  {
    if (node == nullptr)
    {
      throw "Nó não existe na árvore AVL";
    }
    else if (value < node->value)
    {
      return get(value, node->left);
    }
    else if (value > node->value)
    {
      return get(value, node->right);
    }
    else
    {
      return node;
    }
  }
};

#endif // AVLTREE_H_INCLUDED
