#ifndef SPLAYNODE_H_INCLUDED
#define SPLAYNODE_H_INCLUDED

class SplayNode
{
public:
  int key;
  SplayNode *left;
  SplayNode *right;

  SplayNode(int key)
  {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
  };

  ~SplayNode() {};

};

#endif // SPLAYNODE_H_INCLUDED
