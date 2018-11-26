#ifndef SPLAYTREE_H_INCLUDED
#define SPLAYTREE_H_INCLUDED

#include <queue>
#include "SplayNode.hpp"
#include <queue>

class SplayTree
{
public:
  SplayNode *root;
  long long int comparisons;
  long long int copies;

  SplayTree()
  {
    root = nullptr;
    comparisons = 0;
    copies = 0;
  };

  ~SplayTree() {};

  SplayNode* get(int key)
  {
    return getSplay(key);
  }

  SplayNode* insert(int key)
  {
    return insertSplay(key);
  }

  SplayNode* remove(int key)
  {
    return removeSplay(key, root);
  }

  void printKeysByLevel()
  {
    if (root == nullptr)
    {
      return;
    }
    else
    {
      std::queue<SplayNode *> queue;
      queue.push(root);

      while (!queue.empty())
      {
        SplayNode *node = queue.front();

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

  //zig direita
  SplayNode* rotateRight(SplayNode *&node)
  {
    copies += 3;
    SplayNode *pivot = node->right;
    node->right = pivot->left;
    pivot->left = node;
    return pivot;
  }

  //zig esquerda
  SplayNode* rotateLeft(SplayNode *&node)
  {
    copies += 3;
    SplayNode *pivot = node->left;
    node->left = pivot->right;
    pivot->right = node;
    return pivot;
  }

  SplayNode* splay(SplayNode *&node, int key)
  {
    comparisons +=3;
    if (node == nullptr || node->key == key)
    {
      return node;
    }
    if (node->key > key)
    {
      comparisons +=4;
      if (node->left == nullptr){
        return node;
      }
      //zig-zig
      if (node->left->key > key)
      {
        copies =+2;
        node->left->left = splay(node->left->left, key);
        node = rotateRight(node);
      }
      //zig-zag
      else if (node->left->key < key)
      {
        comparisons =+1;
        copies =+1;
        node->left->right = splay(node->left->right, key);
        if (node->left->right != nullptr){
          copies =+1;
          node->left = rotateLeft(node->left);
        }
      }
      if(node->left == nullptr)
      {
        return node;
      }
      else
      {
        return rotateRight(node);
      }
    }
    else
    {
      comparisons +=4;
      if (node->right == nullptr){
        return node;
      }
      //zag-zig
      if (node->right->key > key)
      {
        copies =+1;
        node->right->left = splay(node->right->left, key);
        if (node->right->left != nullptr){
          copies =+1;
          node->right = rotateRight(node->right);
        }
      }
        //zag-zag
      else if (node->right->key < key)
      {
        copies =+2;
        comparisons +=1;
        node->right->right = splay(node->right->right, key);
        node = rotateLeft(node);
      }
      if(node->right == nullptr)
      {
        return node;
      }
      else
      {
        return rotateLeft(node);
      }
    }
  }

  SplayNode* getSplay(int key)
  {
    copies +=1;
    comparisons +=1;
    SplayNode* node = splay(root, key);
    if(node==nullptr)
    {
      throw "Esta chave não existe na árvore";
    }
    else
    {
      return node;
    }
  }

  SplayNode* insertSplay(int key)
  {
    comparisons +=3;
    copies +=2;
    if (root == nullptr){
      copies +=2;
      SplayNode* newNode = new SplayNode(key);
      root = newNode;
      std::cout << "raiz com sucesso" << root->key << "\n" ;
      return newNode;
    }
    root = splay(root, key);
    if (root->key == key){
      throw "Esta chave já existe na árvore";
    }
    SplayNode* newNode = new SplayNode(key);
    if (root->key > key)
    {
      comparisons +=3;
      newNode->right = root;
      newNode->left = root->left;
      root = newNode;
    }
    else
    {
      comparisons +=3;
      newNode->left = root;
      newNode->right = root->right;
      root = newNode;
    }
    std::cout << "incluido com sucesso" << newNode->key << "\n" ;
    return newNode;
  }

  SplayNode* removeSplay(int key, SplayNode *&node)
  {
    return new SplayNode(1);
  }

};

#endif // SPLAYTREE_H_INCLUDED
