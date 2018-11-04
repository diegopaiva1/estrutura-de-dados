/**
 * @file    AVLNode.hpp
 * @author  Diego Paiva e Silva
 * @date    29/10/2018
 *
 * Representação do nó da arvore AVL. O nó contem um chave do tipo inteiro, um filho à esquerda, um filho
 * à direita, altura e seu fator de balanceamento. Um nó AVL é construido inicialmente sem nenhum filho
 * e com altura e fator de balanceamento igual a 0. Estes valores podem ser atualizados nas rotinas a partir
 * dos métodos de atualização updateHeight() e updateBalanceFactor().
 */

#ifndef AVLNODE_H_INCLUDED
#define AVLNODE_H_INCLUDED

class AVLNode
{
public:
  int key;
  AVLNode *left;
  AVLNode *right;
  int height;
  int balanceFactor;

  AVLNode(int key)
  {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 0;
    this->balanceFactor = 0;
  };

  ~AVLNode() {};

  void updateBalanceFactor()
  {
    if (hasNoChildren())
    {
      balanceFactor = 0;
    }
    else if (hasLeftChildOnly())
    {
      balanceFactor = left->height + 1;
    }
    else if (hasRightChildOnly())
    {
      balanceFactor = -(right->height + 1);
    }
    else
    {
      balanceFactor = left->height - right->height;
    }
  }

  void updateHeight()
  {
    if (hasNoChildren())
    {
      height = 0;
    }
    else if (hasLeftChildOnly())
    {
      height = left->height + 1;
    }
    else if (hasRightChildOnly())
    {
      height = right->height + 1;
    }
    else
    {
      if (right->height > left->height)
      {
        height = right->height + 1;
      }
      else
      {
        height = left->height + 1;
      }
    }
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

#endif // AVLNODE_H_INCLUDED
