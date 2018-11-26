/**
 * @file    BNode.hpp
 * @author  Diego Paiva e Silva
 * @date    04/11/2018
 *
 */

#ifndef BNODE_H_INCLUDED
#define BNODE_H_INCLUDED

#include <vector>
#include "../../../algorithms/sorting/InsertionSort.hpp"

class BNode
{
public:
  unsigned int maxDegree;
  bool isLeaf;
  std::vector<int> keys;
  std::vector<BNode *> children;
  InsertionSort *sorter;

  BNode(int maxDegree, bool isLeaf)
  {
    this->maxDegree = maxDegree;
    this->isLeaf = isLeaf;
    this->children.resize(maxDegree + 1);
    this->sorter = new InsertionSort();

    // Armazena até 'maxDegree' chaves (um espaço é reservado para overflow)
    keys.reserve(maxDegree);
  };

  ~BNode() {};

  void insert(int key)
  {
    // Se for folha, insere normalmente e ordena
    if (this->isLeaf)
    {
      keys.push_back(key);
      sorter->sort(keys);
    }
    else
    {
      // Vamos decidir qual o filho irá armazenar esta nova chave e guardaremos o seu index
      BNode *child;
      int index;

      for (unsigned int i = 0; i < keys.size(); i++)
      {
       /* Se ele for menor que o nó que está sendo comparado, já podemos interromper a procura
        * pois sabemos que ele certamente ficará à esquerda deste nó. Caso contrário, continua a
        * busca
        */
        if (key < keys.at(i))
        {
          child = children.at(i);
          index = i;
          break;
        }
        else
        {
          child = children.at(i + 1);
          index = i + 1;
        }
      }

      child->insert(key);

      if (child->hasOverflow())
        split(child, index);
    }
  }

  bool hasOverflow()
  {
    return keys.size() == maxDegree;
  }

  void split(BNode *&splitted, int splittedIndex)
  {
    BNode *node = new BNode(splitted->maxDegree, splitted->isLeaf);

    // Copia metade à direita das chaves do nó a ser dividido para o novo nó
    for (unsigned int i = splitted->keys.capacity() - 1; i > splitted->keys.capacity()/2; i--)
    {
      node->keys.push_back(splitted->keys.at(i));
      splitted->keys.erase(splitted->keys.begin() + i);
    }

    if (!splitted->isLeaf)
    {
      // Copia metade dos filhos à direita do nó a ser dividido para o novo nó
      for (unsigned int i = maxDegree/2 + 1; i < maxDegree + 1; i++)
      {
        node->children.at(i - (maxDegree/2 + 1)) = splitted->children.at(i);
        splitted->children.at(i) = nullptr;
      }
    }

    // Arranja espaço para alocação do novo filho, caso seja necessário
    for (int i = keys.size(); i >= splittedIndex + 1; i--)
      children.at(i + 1) = children.at(i);

    // Linka o novo nó como filho
    children.at(splittedIndex + 1) = node;

    // Promove a chave do meio e a apaga do nó a qual ela pertencia anteriormente
    keys.push_back(splitted->keys.at(maxDegree/2));
    splitted->keys.erase(splitted->keys.begin() + maxDegree/2);

    sorter->sort(keys);
  }
};

#endif // BNODE_H_INCLUDED
