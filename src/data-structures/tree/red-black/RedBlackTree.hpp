/**
 * @file    RedBlackTree.hpp
 * @author  Diego Paiva e Silva
 * @date    14/11/2018
 *
 */

#ifndef REDBLACKTREE_H_INCLUDED
#define REDBLACKTREE_H_INCLUDED

#include "RedBlackNode.hpp"
#include <queue>

class RedBlackTree
{
public:
  RedBlackNode *root;

  RedBlackTree()
  {
    root = nullptr;
  };

  ~RedBlackTree() {};

  void insert(int key)
  {
    RedBlackNode *toBeInserted = new RedBlackNode(key);

    // A inserção atualiza a raíz, caso seja necessário
    root = insert(toBeInserted, root);

    fixTreeProperties(toBeInserted);
  }

  void printKeysByLevel()
  {
    if (root == nullptr)
    {
      return;
    }
    else
    {
      std::queue<RedBlackNode *> queue;
      queue.push(root);

      while (!queue.empty())
      {
        RedBlackNode *node = queue.front();

        std::cout << node->key << " ";

        node->color == RED ? std::cout << "(RED)" << " "
                          : std::cout << "(BLACK)" << " ";

        queue.pop();

        if (node->left != nullptr)
          queue.push(node->left);

        if (node->right != nullptr)
          queue.push(node->right);
      }
      printf("\n");
    }
  }

private:
  RedBlackNode* insert(RedBlackNode *&toBeInserted, RedBlackNode *&node)
  {
    if (node == nullptr)
    {
      return toBeInserted;
    }
    else
    {
      if (toBeInserted->key < node->key)
      {
        node->left = insert(toBeInserted, node->left);
        node->left->parent = node;
      }
      else
      {
        node->right = insert(toBeInserted, node->right);
        node->right->parent = node;
      }
    }

    return node;
  }

private:
 /* Verifica se o nó passado como argumento viola alguma propriedade da AVP e, caso isso ocorra,
  * o ajuste é realizado sequencialmente até que não haja mais violações
  */
  void fixTreeProperties(RedBlackNode *&ptr)
  {
RedBlackNode *parent = nullptr;
    RedBlackNode *grandparent = nullptr;
    while (ptr != root && ptr->isRed() && parent->isRed()) {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            RedBlackNode *uncle = grandparent->right;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->right) {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        } else {
            Node *uncle = grandparent->left;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            } else {
                if (ptr == parent->left) {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
  }

  void rotateLeft(RedBlackNode *&node)
  {
    RedBlackNode *right = node->right;
    node->right = right->left;

    if (node->right != nullptr)
      node->right->parent = node;

    right->parent = node->parent;

    if (node->parent == nullptr)
      root = right;
    else if (node == node->parent->left)
      node->parent->left = right;
    else
      node->parent->right = right;

    right->left = node;
    node->parent = right;
  }

  void rotateRight(RedBlackNode *&node)
  {
    RedBlackNode *left = node->left;
    node->left = left->right;

    if (node->left != nullptr)
      node->left->parent = node;

    left->parent = node->parent;

    if (node->parent == nullptr)
      root = left;
    else if (node == node->parent->left)
      node->parent->left = left;
    else
      node->parent->right = left;

    left->right = node;
    node->parent = left;
  }
};

#endif // REDBLACKTREE_H_INCLUDED
