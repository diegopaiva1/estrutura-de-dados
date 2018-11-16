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

  RedBlackNode* get(int key)
  {
    return get(key, root);
  }

  RedBlackNode* remove(int key)
  {
    return remove(key, root);
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

  RedBlackNode* get(int key, RedBlackNode* node)
  {
    if (node == nullptr)
    {
      throw "Esta chave não existe na árvore";
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

 /* Verifica se o nó passado como argumento viola alguma propriedade da AVP e, caso isso ocorra,
  * o ajuste é realizado sequencialmente até que não haja mais violações
  */
  void fixTreeProperties(RedBlackNode *&node)
  {
    while (node != root && node->isRed() && node->parent->isRed())
    {
      RedBlackNode *parent = node->parent;
      RedBlackNode *grandparent = node->grandparent();

      // Se o tio do nó é vermelho, basta apenas realizar as recolorações
      if (node->hasUncle() && node->uncle()->isRed())
      {
        node->uncle()->recolor();
        parent->recolor();

        if (node->hasGrandparent())
          grandparent->recolor();

        node = grandparent;
      }
      // Caso contrário, é necessário aplicar as rotações & recolorações necessárias
      else
      {
        // Árvore está desbalanceada à esquerda
        if (parent == grandparent->left)
        {
          // Se a condição abaixo é verdadeira, temos um zig-zag (necessário rotação dupla)
          if (node == parent->right)
          {
            rotateLeft(parent);
            node = parent;
            parent = node->parent;
          }

          rotateRight(grandparent);
        }
        // Árvore está desbalanceada à direita
        else if (parent == grandparent->right)
        {
          // Se a condição abaixo é verdadeira, temos um zig-zag (necessário rotação dupla)
          if (node == parent->left)
          {
            rotateRight(parent);
            node = parent;
            parent = node->parent;
          }

          rotateLeft(grandparent);
        }

        // Recoloração pós-rotação
        std::swap(parent->color, grandparent->color);

        node = parent;
      }
    }

    // A raíz é sempre preta!
    root->color = BLACK;
  }

  void rotateLeft(RedBlackNode *&node)
  {
    RedBlackNode *right = node->right;
    node->right = right->left;

    if (node->right != nullptr)
      node->right->parent = node;

    right->parent = node->parent;

    if (!node->hasParent())
      root = right;
    else if (node->isLeftChild())
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

    if (!node->hasParent())
      root = left;
    else if (node->isLeftChild())
      node->parent->left = left;
    else
      node->parent->right = left;

    left->right = node;
    node->parent = left;
  }

  RedBlackNode* remove(int key, RedBlackNode *&node)
  {
    if (node == nullptr)
    {
      throw "Esta chave não pode ser removida pois não está contida na árvore";
    }
    else if (key < node->key)
    {
      node->left = remove(key, node->left);
    }
    else if (key > node->key)
    {
      node->right = remove(key, node->right);
    }
    // A chave de remoção foi encontrada. Os 4 casos possíveis de remoção são tratados.
    else
    {
      if (node->hasNoChildren())
      {
        auto f = node->parent;
        delete node;
        node = nullptr;

        while (node != root)
        {
          if ((node->hasSibling() && node->sibling()->isBlack()) && (node->sibling()->left->isRed() || node->sibling()->right->isRed()))
          {
            RedBlackNode* redChild = node->sibling()->left->isRed() ? node->sibling()->left
                                                                    : node->sibling()->right;

            // Caso 3.2a (III)
            if ((node->sibling()->isRightChild() && redChild->isRightChild()) || (node->sibling()->left->isRed() && node->sibling()->right->isRed()))
            {
              rotateRight(f);
              rotateLeft(f->right);
            }
          }
        }

        return node;
      }
      else if (node->hasLeftChildOnly())
      {
        RedBlackNode *sucessor = node->left;

        if (node->isRed() || sucessor->isRed())
          sucessor->recolor();

        delete node;
        node = nullptr;
        return sucessor;
      }
      else if (node->hasRightChildOnly())
      {
        RedBlackNode *sucessor = node->right;
        delete node;
        node = nullptr;
        return sucessor;
      }
      // No caso seguinte, o nó tem ambos os filhos. Vamos optar pela subárvore à esquerda
      else
      {
        int sucessorKey = getMaxKey(node->left);
        node->key = sucessorKey;
        node->left = remove(sucessorKey, node->left);
      }
    }

    return node;
  }

  int getMinKey(RedBlackNode *node)
  {
    RedBlackNode* min;
    while (node != nullptr)
    {
      min = node;
      node = node->left;
    }
    return min->key;
  }

  int getMaxKey(RedBlackNode *node)
  {
    RedBlackNode* max;
    while (node != nullptr)
    {
      max = node;
      node = node->right;
    }
    return max->key;
  }
};

#endif // REDBLACKTREE_H_INCLUDED
