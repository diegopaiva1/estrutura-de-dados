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

      // Por definição, a raíz é sempre preta
      if (node == root)
      {
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

        if (node->left->hasUncle() && node->left->uncle()->color == RED)
        {
          node->left->father->recolor(root);
          node->left->uncle()->recolor(root);

          if (node->left->hasGrandfather())
            node->grandfather()->recolor(root);
        }
      }
      else
      {
        node->right = insert(key, node->right);
        node->right->father = node;

        if (node->right->hasUncle() && node->right->uncle()->color == RED)
        {
          node->right->uncle()->recolor(root);

          if (node->right->hasFather())
            node->right->father->recolor(root);

          if (node->right->hasGrandfather())
            node->right->grandfather()->recolor(root);
        }
      }
    }

    return node;
  }
};

#endif // REDBLACKTREE_H_INCLUDED
