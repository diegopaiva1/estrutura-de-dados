/**
 * @file    AVLTree.hpp
 * @author  Diego Paiva e Silva
 * @date    29/10/2018
 *
 * Implementação da árvore balanceada AVL com métodos de inserção, busca e remoção.
 * O fator de balanceamento limite default é estipulado na constante BALANCE_FACTOR_LIMIT.
 * Isto siginifica que qualquer nó que apresentar fator de balanceamento maior que BALANCE_FATOR_LIMIT
 * e menor que -BALANCE_FACTOR_LIMIT é considerado desbalanceado e a operação de balanceamento é aplicada.
 */

#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#define BALANCE_FACTOR_LIMIT 1

#include <queue>
#include "AVLNode.hpp"

class AVLTree
{
public:
  AVLNode *root;
  long long int comparisons;
  long long int copies;

  AVLTree()
  {
    root = nullptr;
    comparisons = 0;
    copies = 0;
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

  AVLNode* remove(int key)
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
      std::queue<AVLNode *> queue;
      queue.push(root);

      while (!queue.empty())
      {
        AVLNode *node = queue.front();

        std::cout << node->key << " ";

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
  AVLNode* insert(int key, AVLNode *&node)
  {
    comparisons++;
    if (node == nullptr)
    {
      AVLNode* newNode = new AVLNode(key);

      comparisons++;
      if (node == root)
        root = newNode;

      return newNode;
    }
    else
    {
      comparisons++;
      if (key < node->key)
      {
        copies++;
        node->left = insert(key, node->left);
      }
      else
      {
        copies++;
        node->right = insert(key, node->right);
      }

     /* Atualiza os valores pós-inserção para retornar o nó balanceado
      * posteriormente (caso seja necessário balanceá-lo)
      */
      node->updateHeight();
      node->updateBalanceFactor();
    }

    return balance(node);
  }

  AVLNode* balance(AVLNode *&node)
  {
    comparisons++;
    if (node->balanceFactor == BALANCE_FACTOR_LIMIT + 1)
    {
      comparisons++;
      // Neste caso temos um zig-zag (necessário rotação dupla)
      if (node->left->balanceFactor == -BALANCE_FACTOR_LIMIT)
      {
        copies++;
        node->left = rotateRight(node->left);
      }

      return rotateLeft(node);
    }
    else if (node->balanceFactor == -BALANCE_FACTOR_LIMIT - 1)
    {
      comparisons++;
      // Neste caso temos um zig-zag (necessário rotação dupla)
      if (node->right->balanceFactor == BALANCE_FACTOR_LIMIT)
      {
        copies++;
        node->right = rotateLeft(node->right);
      }

      return rotateRight(node);
    }

    return node;
  }

  AVLNode* rotateRight(AVLNode *&node)
  {
    copies += 3;
    AVLNode *pivot = node->right;
    node->right = pivot->left;
    pivot->left = node;

    updatePivot(pivot, node);

    return pivot;
  }

  AVLNode* rotateLeft(AVLNode *&node)
  {
    copies += 3;
    AVLNode *pivot = node->left;
    node->left = pivot->right;
    pivot->right = node;

    updatePivot(pivot, node);

    return pivot;
  }

  void updatePivot(AVLNode *&pivot, AVLNode *&node)
  {
    comparisons++;
    if (pivot->left != nullptr)
    {
      pivot->left->updateHeight();
      pivot->left->updateBalanceFactor();
    }

    comparisons++;
    if (pivot->right != nullptr)
    {
      pivot->right->updateHeight();
      pivot->right->updateBalanceFactor();
    }

    pivot->updateHeight();
    pivot->updateBalanceFactor();

    comparisons++;
    if (node == root)
    {
      copies++;
      root = pivot;
    }
  }

  AVLNode* get(int key, AVLNode* node)
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

  AVLNode* remove(int key, AVLNode *&node)
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
        delete node;
        node = nullptr;
        return node;
      }
      else if (node->hasLeftChildOnly())
      {
        AVLNode *sucessor = node->left;
        delete node;
        node = nullptr;
        return sucessor;
      }
      else if (node->hasRightChildOnly())
      {
        AVLNode *sucessor = node->right;
        delete node;
        node = nullptr;
        return sucessor;
      }
     /* No caso seguinte, o nó tem ambos os filhos. De modo a facilitar o balanceamento posteriormente,
      * o sucessor é escolhido ná arvore que possui maior número de nós (maior altura).
      * Se for escolhida a subárvore à esquerda então procuramos o nó com a maior chave,
      * senão escolhemos a subárvore à direita e procuramos o nó com a menor chave
      */
      else
      {
        if (node->left->height > node->right->height)
        {
          int sucessorKey = getMaxKey(node->left);
          node->key = sucessorKey;
          node->left = remove(sucessorKey, node->left);
        }
        else
        {
          int sucessorKey = getMinKey(node->right);
          node->key = sucessorKey;
          node->right = remove(sucessorKey, node->right);
        }
      }
    }

   /* Após a remoção, atualizamos altura e fator de balanceamento do nó
    * pai do nó que foi removido para balanceá-lo caso seja necessário
    */
    node->updateHeight();
    node->updateBalanceFactor();

    return balance(node);
  }

  int getMinKey(AVLNode *node)
  {
    AVLNode* min;

    while (node != nullptr)
    {
      min = node;
      node = node->left;
    }

    return min->key;
  }

  int getMaxKey(AVLNode *node)
  {
    AVLNode* max;

    while (node != nullptr)
    {
      max = node;
      node = node->right;
    }

    return max->key;
  }
};

#endif // AVLTREE_H_INCLUDED
