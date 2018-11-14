/**
 * @file    RedBlackTree.hpp
 * @author  Diego Paiva e Silva
 * @date    14/11/2018
 *
 */

#ifndef REDBLACKTREE_H_INCLUDED
#define REDBLACKTREE_H_INCLUDED

#include "RedBlackNode.hpp"

class RedBlackTree
{
public:
  RedBlackNode *root;

  RedBlackTree()
  {
    root = nullptr;
  };

  ~RedBlackTree() {};

  RedBlackNode* insert(int key)
  {
    return insert(key, root);
  }

private:
  RedBlackNode* insert(int key, RedBlackNode *&node)
  {
    if (node == nullptr)
    {
      RedBlackNode *insertedNode = new RedBlackNode(key);

      if (node == root)
      {
        // Por definição, a raíz é sempre preta
        insertedNode->color = BLACK;
        root = insertedNode;
      }

      return insertedNode;
    }
    else
    {
      if (key < node->key)
      {
        node->left = insert(key, node->left);
        node->left->father = node;

        // Se o tio do nó recém-inserido for vermelho, basta realizar as recolorações
        if (node->left->hasUncle() && node->left->uncle()->isRed())
        {
          node->left->father->recolor(root);
          node->left->uncle()->recolor(root);

          if (node->left->hasGrandfather())
            node->grandfather()->recolor(root);
        }
        // Caso contrário, é necessário aplicar as rotações necessárias & recolorir
        else
        {
          if (node->left->father->isRed() && (!node->left->hasUncle() || node->left->uncle()->isBlack()))
          {
            rotateRight(node->father);
            node->left->father->recolor(root);
            node->left->grandfather()->recolor(root);
          }
        }
      }
      else
      {
        node->right = insert(key, node->right);
        node->right->father = node;

        // Se o tio do nó recém-inserido for vermelho, basta realizar as recolorações
        if (node->right->hasUncle() && node->right->uncle()->isRed())
        {
          node->right->uncle()->recolor(root);

          if (node->right->hasFather())
            node->right->father->recolor(root);

          if (node->right->hasGrandfather())
            node->right->grandfather()->recolor(root);
        }
        // Caso contrário, é necessário aplicar as rotações necessárias & recolorir
        else
        {
          if (node->right->father->isRed() && (!node->right->hasUncle() || node->right->uncle()->isBlack()))
          {
            node->father->left = rotateRight(node->father->left);
          }
        }
      }
    }

    return node;
  }

private:
  RedBlackNode* rotateRight(RedBlackNode *&node)
  {
    RedBlackNode *pivot = node->left;
    node->left = pivot->right;
    pivot->right = node;

    if (node == root)
      root = pivot;

    return pivot;
  }
};

#endif // REDBLACKTREE_H_INCLUDED
