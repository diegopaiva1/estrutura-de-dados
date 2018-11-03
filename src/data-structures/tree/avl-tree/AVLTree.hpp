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
    if (root != nullptr)
    {
      return root->height;
    }
    else
    {
      return -1;
    }
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

      /* Atualiza os valores pós-inserção para retornar o nó balanceado
       * posteriormente, caso seja necessário balanceá-lo
       */
      node->updateHeight();
      node->updateBalanceFactor();
    }

    return balance(node);
  }

  AVLNode* balance(AVLNode *&node)
  {
    if (node->balanceFactor == BALANCE_FACTOR_LIMIT + 1)
    {
      // Neste caso, temos um zig-zag (necessário rotação dupla)
      if (node->left->balanceFactor == -BALANCE_FACTOR_LIMIT)
      {
        node->left = rotateRight(node->left);
      }

      return rotateLeft(node);
    }
    else if (node->balanceFactor == -BALANCE_FACTOR_LIMIT - 1)
    {
      // Neste caso, temos um zig-zag (necessário rotação dupla)
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
    AVLNode *pivot = node->right;
    node->right = pivot->left;
    pivot->left = node;

    updatePivot(pivot, node);

    return pivot;
  }

  AVLNode* rotateLeft(AVLNode *&node)
  {
    AVLNode *pivot = node->left;
    node->left = pivot->right;
    pivot->right = node;

    updatePivot(pivot, node);

    return pivot;
  }

  void updatePivot(AVLNode *&pivot, AVLNode *&node)
  {
    if (pivot->left != nullptr)
    {
      pivot->left->updateHeight();
      pivot->left->updateBalanceFactor();
    }

    if (pivot->right != nullptr)
    {
      pivot->right->updateHeight();
      pivot->right->updateBalanceFactor();
    }

    pivot->updateHeight();
    pivot->updateBalanceFactor();

    if (node == root)
    {
      root = pivot;
    }
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
