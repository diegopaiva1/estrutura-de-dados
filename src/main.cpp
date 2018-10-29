#include <iostream>
#include "data-structures/tree/avl-tree/AVLTree.hpp"

int main(int argc, char const *argv[])
{
  AVLTree *avlTree = new AVLTree();

  avlTree->insert(74);
  avlTree->insert(30);
  avlTree->insert(20);
  avlTree->insert(90);

  try
  {
    std::cout << avlTree->root->value << std::endl;
    auto node = avlTree->get(30);
    std::cout << "Filho à esquerda do nó " << node->value << ": " << node->left->value << std::endl;
    std::cout << "Filho à direita do nó " << node->value << ": " << node->right->value << std::endl;
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  return 0;
}
