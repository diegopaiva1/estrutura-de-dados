#include <iostream>
#include <time.h>
#include "data-structures/tree/red-black/RedBlackTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  RedBlackTree *redBlackTree = new RedBlackTree();

  for (int i = 1; i < 50; i++)
    redBlackTree->insert(rand() % 50 + 1);

  try
  {
    std::cout << redBlackTree->get(11)->key << '\n';
  }
  catch (const char* exception)
  {
    std::cerr << exception << '\n';
  }

  // redBlackTree->printKeysByLevel();

  return 0;
}
