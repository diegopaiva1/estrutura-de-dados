#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#define BALANCE_FACTOR_LIMIT 1

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
    return root->height;
  }

  AVLNode* insert(int key)
  {
    return insert(key, root);
  }

  AVLNode* get(int key)
  {
    return get(key, root);
  }

private:
  AVLNode* insert(int key, AVLNode *&node)
  {
    if (node == nullptr)
    {
      return new AVLNode(key);
    }
    else
    {
      if (key < node->key)
      {
        node->left = insert(key, node->left);
      }
      else
      {
        node->right = insert(key, node->right);
      }

      node->updateHeight();
      node->updateBalanceFactor();

      node = balance(node);
    }

    return node;
  }

  AVLNode* balance(AVLNode *&node)
  {
    if (node->balanceFactor > BALANCE_FACTOR_LIMIT)
    {
      if (node->left->balanceFactor == -BALANCE_FACTOR_LIMIT)
      {
        node->left = rotateRight(node->left);
      }

      return rotateLeft(node);
    }
    else if (node->balanceFactor < -BALANCE_FACTOR_LIMIT)
    {
      if (node->right->balanceFactor == BALANCE_FACTOR_LIMIT)
      {
        node->right = rotateLeft(node->right);
      }

      return rotateRight(node);
    }

    return node;
  }

  AVLNode* rotateRight(AVLNode *&node)
  {
    AVLNode *rotated = node->right;
    node->right = rotated->left;
    rotated->left = node;

    if (rotated->left != nullptr)
    {
      rotated->left->updateHeight();
      rotated->left->updateBalanceFactor();
    }

    if (rotated->right != nullptr)
    {
      rotated->right->updateHeight();
      rotated->right->updateBalanceFactor();
    }

    rotated->updateHeight();
    rotated->updateBalanceFactor();

    if (node == root)
    {
      root = rotated;
    }

    return rotated;
  }

  AVLNode* rotateLeft(AVLNode *&node)
  {
    AVLNode *rotated = node->left;
    node->left = rotated->right;
    rotated->right = node;

    if (rotated->left != nullptr)
    {
      rotated->left->updateHeight();
      rotated->left->updateBalanceFactor();
    }

    if (rotated->right != nullptr)
    {
      rotated->right->updateHeight();
      rotated->right->updateBalanceFactor();
    }

    rotated->updateHeight();
    rotated->updateBalanceFactor();

    if (node == root)
    {
      root = rotated;
    }

    return rotated;
  }

  AVLNode* get(int key, AVLNode* node)
  {
    if (node == nullptr)
    {
      throw "Esta chave não existe na árvore AVL";
    }
    else if (key < node->key)
    {
      return get(key, node->left);
    }
    else if (key > node->key)
    {
      return get(key, node->right);
    }
    else
    {
      return node;
    }
  }
};

#endif // AVLTREE_H_INCLUDED
