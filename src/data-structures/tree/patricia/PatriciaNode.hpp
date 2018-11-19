/**
 * @file    PatriciaNode.hpp
 * @author  Diego Paiva e Silva
 * @date    18/11/2018
 *
 */

#ifndef PATRICIANODE_H_INCLUDED
#define PATRICIANODE_H_INCLUDED

#include <vector>

#define ALPHABET_SIZE 26

class PatriciaNode
{
public:
  std::vector<PatriciaNode *> children;
  char* word;
  bool isCompleteWord;

  PatriciaNode(char* word)
  {
    this->word = word;
    children.resize(ALPHABET_SIZE);
    isCompleteWord = true;
  }

  ~PatriciaNode() {}
};

#endif // PATRICIANODE_H_INCLUDED
