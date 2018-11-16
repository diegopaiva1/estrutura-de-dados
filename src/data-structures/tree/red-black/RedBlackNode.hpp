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
  RedBlackNode *parent;
  RedBlackNode *left;
  RedBlackNode *right;
  Color color;

  RedBlackNode(int key)
  {
    this->key = key;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->color = RED;
  };

  ~RedBlackNode() {};

  RedBlackNode* uncle()
  {
    if (hasGrandparent())
    {
      if (grandparent()->left == parent)
        return grandparent()->right;
      else
        return grandparent()->left;
    }

    return nullptr;
  }

  RedBlackNode* sibling()
  {
    if (this->isLeftChild())
      return parent->right;
    else
      return parent->left;
  }

  RedBlackNode* grandparent() { return parent->parent; }

  bool hasUncle() { return uncle() != nullptr; }

  bool hasGrandparent() { return grandparent() != nullptr; }

  bool hasSibling() { return sibling() != nullptr; }

  bool hasParent() { return parent != nullptr; }

  bool isLeftChild() { return this == parent->left; }

  bool isRightChild() { return this == parent->right; }

  void recolor() { color == RED ? color = BLACK : color = RED; }

  bool isRed() { return color == RED; }

  bool isBlack() { return color == BLACK; }

  bool hasNoChildren() { return right == nullptr && left == nullptr; }

  bool hasLeftChildOnly() { return left != nullptr && right == nullptr; }

  bool hasRightChildOnly() { return right != nullptr && left == nullptr; }
};

#endif // REDBLACKNODE_H_INCLUDED
