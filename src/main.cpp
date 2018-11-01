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
  avlTree->insert(6);
  avlTree->insert(7);
  avlTree->insert(15);
  avlTree->insert(14);
  avlTree->insert(13);
  avlTree->insert(12);
  avlTree->insert(11);

  try
  {
    std::cout << "Imprimindo nós por nível para teste" << '\n';
    std::cout << avlTree->root->key << '\n';
    std::cout << avlTree->root->left->key << " " << avlTree->root->right->key << '\n';
    std::cout << avlTree->root->left->left->key << " " << avlTree->root->left->right->key << " "
              << avlTree->root->right->left->key << " " << avlTree->root->right->right->key << '\n';
    std::cout << avlTree->root->left->left->left->key << " "
              << avlTree->root->left->left->right->key << " "
              << avlTree->root->left->right->left->key << " "
              << avlTree->root->right->left->left->key << " "
              << avlTree->root->right->left->right->key << '\n';
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  return 0;
}
