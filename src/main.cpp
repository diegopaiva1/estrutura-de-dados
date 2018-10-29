#include <iostream>
#include "data-structures/tree/avl-tree/AVLTree.hpp"

int main(int argc, char const *argv[])
{
  AVLTree *avlTree = new AVLTree();

  avlTree->root = avlTree->insert(74);
  avlTree->insert(30);
  avlTree->insert(20);
  avlTree->insert(90);

  try
  {
    std::cout << avlTree->get(110)->value << std::endl;
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  return 0;
}
