/**
 * @file    RedBlackNode.hpp
 * @author  Diego Paiva e Silva
 * @date    14/11/2018
 *
 */

#ifndef REDBLACKNODE_H_INCLUDED
#define REDBLACKNODE_H_INCLUDED

enum Color {RED, BLACK};

class RedBlackNode
{
public:
  int key;
  RedBlackNode *father;
  RedBlackNode *left;
  RedBlackNode *right;
  Color color;

  RedBlackNode(int key)
  {
    this->key = key;
    this->father = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->color = RED;
  };

  ~RedBlackNode() {};

  bool hasUncle()
  {
    return uncle() != nullptr;
  }

  RedBlackNode* uncle()
  {
    if (hasGrandfather())
    {
      if (grandfather()->left == father)
        return grandfather()->right;
      else
        return grandfather()->left;
    }

    return nullptr;
  }

  bool hasGrandfather()
  {
    return grandfather() != nullptr;
  }

  RedBlackNode* grandfather()
  {
    return father->father;
  }

  bool hasFather()
  {
    return father != nullptr;
  }

  void recolor(RedBlackNode *root)
  {
    color == RED ? color = BLACK : color = RED;

    // A raíz é sempre preta!
    if (this == root)
      color = BLACK;
  }

  bool isRed()
  {
    return color == RED;
  }

  bool isBlack()
  {
    return color == BLACK;
  }

  bool hasNoChildren()
  {
    return right == nullptr && left == nullptr;
  }

  bool hasLeftChildOnly()
  {
    return left != nullptr && right == nullptr;
  }

  bool hasRightChildOnly()
  {
    return right != nullptr && left == nullptr;
  }
};

#endif // REDBLACKNODE_H_INCLUDED
