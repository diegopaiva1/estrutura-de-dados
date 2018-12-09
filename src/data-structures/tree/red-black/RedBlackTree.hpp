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
  long long int copies;
  long long int comparisons;

  RedBlackTree()
  {
    root = nullptr;
  };

  ~RedBlackTree() {};

  void insert(int key)
  {
    copies++;
    RedBlackNode *toBeInserted = new RedBlackNode(key);

    copies++;
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
    comparisons++;
    if (node == nullptr)
    {
      return toBeInserted;
    }
    else
    {
      comparisons++;
      if (toBeInserted->key < node->key)
      {
        copies += 2;
        node->left = insert(toBeInserted, node->left);
        node->left->parent = node;
      }
      else
      {
        copies += 2;
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
      comparisons++;
      return node;
    }
    else if (key < node->key)
    {
      comparisons += 2;
      return get(key, node->left);
    }
    else if (key > node->key)
    {
      comparisons += 3;
      return get(key, node->right);
    }
    else
    {
      return node;
    }
  }

 /* Verifica se o nó passado como argumento viola alguma propriedade da AVP e, caso isso ocorra,
  * o ajuste é realizado sequencialmente até que não hajam mais violações
  */
  void fixTreeProperties(RedBlackNode *&node)
  {
    while (node != root && node->isRed() && node->parent->isRed())
    {
      comparisons++;
      copies += 2;
      RedBlackNode *parent = node->parent;
      RedBlackNode *grandparent = node->grandparent();

      comparisons++;
      // Se o tio do nó é vermelho, basta apenas realizar as recolorações
      if (node->hasUncle() && node->uncle()->isRed())
      {
        copies += 2;
        node->uncle()->recolor();
        parent->recolor();

        comparisons++;
        if (node->hasGrandparent())
        {
          copies++;
          grandparent->recolor();
        }

        copies++;
        node = grandparent;
      }
      // Caso contrário, é necessário aplicar as rotações & recolorações necessárias
      else
      {
        comparisons++;
        // Árvore está desbalanceada à esquerda
        if (parent == grandparent->left)
        {
          // Se a condição abaixo é verdadeira, temos um zig-zag (necessário rotação dupla)
          if (node == parent->right)
          {
            comparisons++;
            rotateLeft(parent);
            copies += 2;
            node = parent;
            parent = node->parent;
          }

          rotateRight(grandparent);
        }
        // Árvore está desbalanceada à direita
        else if (parent == grandparent->right)
        {
          comparisons += 2;
          // Se a condição abaixo é verdadeira, temos um zig-zag (necessário rotação dupla)
          comparisons++;
          if (node == parent->left)
          {
            rotateRight(parent);
            copies += 2;
            node = parent;
            parent = node->parent;
          }

          rotateLeft(grandparent);
        }

        copies += 3;
        // Recoloração pós-rotação
        std::swap(parent->color, grandparent->color);

        copies++;
        node = parent;
      }
    }

    copies++;
    // A raíz é sempre preta!
    root->color = BLACK;
  }

  void rotateLeft(RedBlackNode *&node)
  {
    RedBlackNode *right = node->right;
    node->right = right->left;

    comparisons++;
    if (node->right != nullptr)
    {
      copies++;
      node->right->parent = node;
    }

    right->parent = node->parent;

    if (!node->hasParent())
    {
      comparisons++;
      root = right;
    }
    else if (node->isLeftChild())
    {
      comparisons += 2;
      node->parent->left = right;
    }
    else
    {
      comparisons += 2;
      node->parent->right = right;
    }

    right->left = node;
    node->parent = right;

    copies += 6;
  }

  void rotateRight(RedBlackNode *&node)
  {
    RedBlackNode *left = node->left;
    node->left = left->right;

    comparisons++;
    if (node->left != nullptr)
    {
      copies++;
      node->left->parent = node;
    }

    copies++;
    left->parent = node->parent;

    if (!node->hasParent())
    {
      comparisons++;
      root = left;
    }
    else if (node->isLeftChild())
    {
      comparisons += 2;
      node->parent->left = left;
    }
    else
    {
      comparisons += 2;
      node->parent->right = left;
    }

    left->right = node;
    node->parent = left;

    copies += 6;
  }

  RedBlackNode* remove(int key, RedBlackNode *&node)
  {
    if (node == nullptr)
    {
      throw "A chave não pode ser removida pois não está contida na árvore";
    }
    else if (key < node->key)
    {
      node->left = remove(key, node->left);
    }
    else if (key > node->key)
    {
      node->right = remove(key, node->right);
    }
    // A chave de remoção foi encontrada. Os casos possíveis de remoção são tratados.
    else
    {
     /* O nó é deletado, mas sua referência na memória ainda existe, por isso podemos continuar
      * acessando suas informações. No fim do bloco a referência é removida
      */
      delete node;

      RedBlackNode* sucessor;

      if (node->hasNoChildren())
      {
        sucessor = nullptr;
      }
      else if (node->hasLeftChildOnly())
      {
        sucessor = node->left;
      }
      else if (node->hasRightChildOnly())
      {
        sucessor = node->right;
      }
      else
      {
        int sucessorKey = getMaxKey(node->left);
        node->key = sucessorKey;
        node->left = remove(sucessorKey, node->left);
      }

      // Caso mais simples
      if (node->isRed() || (sucessor != nullptr && sucessor->isRed()))
      {
        sucessor->recolor();
      }
      else if (node->isBlack() || node->hasNoChildren())
      {
        // Se tirar esse cout de baixo o programa crasha... Só Deus sabe o porquê. Então deixa ela quieta ai
        std::cout << " ";

        node->color = DOUBLE_BLACK;

        while (node->color == DOUBLE_BLACK && node != root)
        {
          if ( (node->hasSibling() && node->sibling()->isBlack()) &&
               (node->sibling()->left->isRed() || node->sibling()->right->isRed()) )
          {
            RedBlackNode* redChild = node->sibling()->left->isRed() ? node->sibling()->left
                                                                    : node->sibling()->right;
            // Caso 3.2a (I)
            if ( (node->sibling()->isLeftChild() && redChild->isLeftChild()) ||
                 (node->sibling()->left->isRed() && node->sibling()->right->isRed()) )
              rotateRight(node->parent);

            // Caso 3.2a (III)
            else if ( (node->sibling()->isRightChild() && redChild->isRightChild()) ||
                      (node->sibling()->left->isRed() && node->sibling()->right->isRed()) )
              rotateLeft(node->parent);

            // Caso 3.2a (IV)
            else if (node->sibling()->isRightChild() && redChild->isLeftChild())
            {
              RedBlackNode* sibling = node->sibling();

              rotateRight(sibling);
              rotateLeft(sibling);
            }
          }

          node = node->parent;
        }
      }

      node = nullptr;

      return sucessor;
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
