#include <iostream>
#include <time.h>
#include "data-structures/tree/avl-tree/AVLTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  AVLTree *avlTree = new AVLTree();

  for (int i = 0; i < 60000; i++)
  {
    int number = rand() % 60000 + 1;
    if (i == 0)
    {
      avlTree->root = avlTree->insert(number);
    }
    else
    {
      avlTree->insert(number);
    }
  }

  try
  {
    std::cout << avlTree->get(59432)->key << '\n';
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  return 0;
}
