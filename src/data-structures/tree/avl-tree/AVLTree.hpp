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

  AVLNode* insert(int key)
  {
    return insert(key, root);
  }

  AVLNode* get(int key)
  {
    return get(key, root);
  }

private:
  AVLNode* insert(int key, AVLNode* node)
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
