#include <iostream>
#include <time.h>
#include "data-structures/tree/avl-tree/AVLTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  AVLTree *avlTree = new AVLTree();

  // for (int i = 0; i < 10000; i++)
  // {
  //   int number = rand() % 10000 + 1;
  //   if (i == 0)
  //   {
  //     avlTree->root = avlTree->insert(number);
  //   }
  //   else
  //   {
  //     avlTree->insert(number);
  //   }
  // }

  avlTree->root = avlTree->insert(10);
  avlTree->insert(5);
  avlTree->insert(18);
  avlTree->insert(1);
  avlTree->insert(9);
  avlTree->insert(13);
  avlTree->insert(22);

  try
  {
    avlTree->remove(200);
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  try
  {
    std::cout << "Imprimindo nós por nível para teste" << '\n';
    std::cout << avlTree->root->key << '\n';
    std::cout << avlTree->root->left->key << " " << avlTree->root->right->key << '\n';
    std::cout << avlTree->root->left->left->key << " " << avlTree->root->left->right->key << " "
              << avlTree->root->right->right->key << '\n';
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  return 0;
}
