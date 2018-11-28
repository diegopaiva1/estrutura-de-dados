#include <iostream>
#include <time.h>
#include "data-structures/tree/red-black/RedBlackTree.hpp"
#include "data-structures/tree/avl/AVLTree.hpp"
#include "data-structures/tree/b/BTree.hpp"
#include "data-structures/tree/splay/SplayTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  BTree *bTree = new BTree(7);

  bTree->insert(9);
  bTree->insert(120);
  bTree->insert(13);
  bTree->insert(45);
  bTree->insert(155);
  bTree->insert(1023);
  bTree->insert(71);
  bTree->insert(88);
  bTree->insert(901);
  bTree->insert(12);
  bTree->insert(378);
  bTree->insert(4);

  try
  {
     bTree->remove(88);
  }
  catch (const char* exception)
  {
    std::cerr << exception << '\n';
  }

  /*
  SplayTree *splayTree = new SplayTree();

  splayTree->insert(9);
  splayTree->insert(120);
  splayTree->insert(13);
  splayTree->insert(45);
  splayTree->insert(155);
  splayTree->insert(1023);
  splayTree->insert(71);
  splayTree->insert(88);
  splayTree->insert(901);
  splayTree->insert(12);
  splayTree->insert(378);
  splayTree->insert(4);

  splayTree->printKeysByLevel();

  try
  {
    std::cout << splayTree->remove(88)->key << '\n';
  }
  catch (const char* exception)
  {
    std::cerr << exception << '\n';
  }*/

  return 0;
}
