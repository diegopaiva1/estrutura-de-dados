#include <iostream>
#include "data-structures/tree/avl-tree/AVLTree.hpp"

int main(int argc, char const *argv[])
{
  AVLTree *avlTree = new AVLTree();

  avlTree->root = avlTree->insert(1);
  avlTree->insert(2);
  avlTree->insert(8);
  avlTree->insert(10);
  avlTree->insert(12);
  avlTree->insert(9);

  try
  {
    std::cout << "Raíz = " << avlTree->root->key << std::endl;
    std::cout << "Fator de balanceamento da raíz = " << avlTree->root->balanceFactor() << std::endl;
    std::cout << "Esquerda da raíz = " << avlTree->root->left->key << std::endl;
    std::cout << "Fator de balanceamento da esquerda = " << avlTree->root->left->balanceFactor() << std::endl;
    std::cout << "Direita da raíz = " << avlTree->root->right->key << std::endl;
    std::cout << "Fator de balanceamento da direita = " << avlTree->root->right->balanceFactor() << std::endl;
    std::cout << "Direita da direita = " << avlTree->root->right->right->key << std::endl;
    std::cout << "Esquerda da direita = " << avlTree->root->right->left->key << std::endl;
    std::cout << "Fator de balanceamento da direita da direita = " << avlTree->root->right->right->balanceFactor() << std::endl;
    std::cout << "Fator de balanceamento da esquerda da direita = " << avlTree->root->right->left->balanceFactor() << std::endl;
    std::cout << "Altura da árvore = " << avlTree->height() << std::endl;
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  return 0;
}
