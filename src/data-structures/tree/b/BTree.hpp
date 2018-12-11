/**
 * @file    BTree.hpp
 * @author  Diego Paiva e Silva
 * @date    04/11/2018
 *
 */

#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

#include "BNode.hpp"

class BTree
{
public:
  unsigned int maxDegree;
  BNode *root;

  BTree(int maxDegree)
  {
    this->maxDegree = maxDegree;
    this->root = nullptr;
  };

  ~BTree() {};

  void insert(int key)
  {
    if (root == nullptr)
    {
      root = new BNode(maxDegree, true);
      root->insert(key);
    }
    else
    {
      root->insert(key);

      if (root->hasOverflow())
      {
        // Crescimento bottom-up: atual raíz passa a ser filho de um novo nó
        BNode *node = new BNode(maxDegree, false);
        node->children.at(0) = root;
        root = node;
        node->split(node->children.at(0), 0);
      }
    }
  }

  int get(int key)
  {
    BNode *node = root;

    while (node != nullptr)
    {
      unsigned int index = 0;

      while (index < node->keys.size() && key > node->keys.at(index))
        index++;

      if (index < node->keys.size() && key == node->keys.at(index))
        return node->keys.at(index);

      node = node->children.at(index);
    }

    // Se chegou até aqui, todas as possibilidades foram exploradas
    throw "Chave inexistente na árvore B";
  }

  BNode* getNode(int key)
  {
    BNode *node = root;

    while (node != nullptr)
    {
      unsigned int index = 0;

      while (index < node->keys.size() && key > node->keys.at(index))
        index++;

      if (index < node->keys.size() && key == node->keys.at(index))
        return node;

      node = node->children.at(index);
    }

    throw "Chave inexistente na árvore B";
  }

  void remove(int key)
  {
    BNode *node = getNode(key);
    unsigned int index = 0;
    while (index < node->keys.size() && key > node->keys.at(index)){
      index++;
    }
    if (index < node->keys.size() && key == node->keys.at(index))
      if(node->isLeaf)
      {
        node->keys.erase (node->keys.begin()+index);
      }
      else
      {
        BNode* nearest = node->children.at(index+1);
        if(nearest->keys.front()!=NULL)
        {
          std::swap(node->keys.at(index), nearest->keys.front());
        }
        else
        {
          nearest = node->children.at(index);
          std::swap(node->keys.at(index), nearest->keys.back());
        }
        node->keys.erase (node->keys.begin()+index);
      }
      if(node->hasUnderflow() && node!=root)
      {
        fixUnderflow(node);
      }
    }

    void fixUnderflow(BNode* &nodeBrother)
    {
      BNode *leftBrother;
      BNode *rightBrother;
      BNode *node = root;
      BNode *aux;
      bool fixed = false;
      int key;

      key = nodeBrother->keys.front();
      while (node != nullptr)
      {
        unsigned int index = 0;

        while (index < node->keys.size() && key > node->keys.at(index))
          index++;

        aux = node->children.at(index);
        if (aux->keys.front()==key)
        {
          leftBrother = node->children.at(index-1);
          if (leftBrother->hasMinimumNumberKeys())
          {
            leftBrother->insert(node->keys.at(index-1)); //index
            for (auto k = nodeBrother->keys.begin(); k != nodeBrother->keys.end(); k++)
            {
              leftBrother->insert(*k);
            }
            node->children.at(index) = leftBrother;
            node->keys.erase(node->keys.begin()+(index-1));//index
            node->children.erase(node->children.begin()+(index-1));
            if(node->hasUnderflow() && node!=root)
            {
              fixUnderflow(node);
            }
          }
          else
          {
            nodeBrother->insert(node->keys.at(index-1));
            int i=0;
            for (auto k = leftBrother->keys.begin(); k != leftBrother->keys.end(); k++)
            {
              if(i==leftBrother->maxDegree)
              {
                std::swap(node->keys.at(index-1), *k);
              }
              if(i>leftBrother->maxDegree)
              {
                nodeBrother->insert(*k);
              }
              i++;
            }
          }
        }
        else
        {
          node = node->children.at(index);
        }
      }

      if(!fixed){
        node = root;
        int key = nodeBrother->keys.back();
        while (node != nullptr)
        {
          unsigned int index = 0;

          while (index < node->keys.size() && key > node->keys.at(index))
            index++;

          aux = node->children.at(index);
          if (aux->keys.back()==key)
          {
            rightBrother = node->children.at(index+1);
            if (rightBrother->hasMinimumNumberKeys())
            {
              rightBrother->insert(node->keys.at(index));
              for (auto k = nodeBrother->keys.begin(); k != nodeBrother->keys.end(); k++)
              {
                rightBrother->insert(*k);
              }
              node->children.at(index) = rightBrother;
              node->keys.erase(node->keys.begin()+index);
              node->children.erase(node->children.begin()+(index-1));
              if(node->hasUnderflow() && node!=root)
              {
                fixUnderflow(node);
              }
            }

            {
              nodeBrother->insert(node->keys.at(index));
              int i=0;
              for (auto k = rightBrother->keys.begin(); k != rightBrother->keys.end(); k++)
              {
                if(i==rightBrother->maxDegree)
                {
                  std::swap(node->keys.at(index), *k);
                }
                if(i>rightBrother->maxDegree)
                {
                  nodeBrother->insert(*k);
                }
                i++;
              }
            }
          }
          else
          {
            node = node->children.at(index);
          }
        }
      }
    }

  };

#endif // BTREE_H_INCLUDED
