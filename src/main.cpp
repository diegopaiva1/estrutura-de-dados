#include <iostream>
#include <time.h>
#include "data-structures/tree/b/BTree.hpp"

int main(int argc, char const *argv[])
{
  srand(time(NULL));

  BTree *b = new BTree(4);

  for (int i = 0; i < 500000; i++)
  {
    b->insert(rand() % 500000 + 1);
  }

  try
  {
    std::cout << b->get(11000) << '\n';
  }
  catch (const char* exception)
  {
    std::cerr << exception << std::endl;
  }

  return 0;
}
