#include <iostream>
#include "data-structures/tree/avl-tree/AVLTree.hpp"

int main(int argc, char const *argv[])
{
  AVLTree *avlTree = new AVLTree();

  avlTree->root = avlTree->insert(1);
  avlTree->insert(2);
  avlTree->insert(3);
  avlTree->insert(4);
  avlTree->insert(5);

  try
  {
    std::cout << "Fator de balanceamento da raíz = " << avlTree->root->balanceFactor() << std::endl;
    std::cout << "Raíz da árvore = " << avlTree->root->key << std::endl;
    std::cout << "Filho à esquerda da raíz = " << avlTree->root->left->key << std::endl;
    std::cout << "Filho à direita da raíz = " << avlTree->root->right->key << std::endl;
    std::cout << "Altura da árvore = " << avlTree->height() << std::endl;
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  return 0;
}
