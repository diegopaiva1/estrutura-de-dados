#ifndef AVLNODE_H_INCLUDED
#define AVLNODE_H_INCLUDED

class AVLNode
{
public:
  int value;
  AVLNode *left;
  AVLNode *right;
  int balanceFactor;

  AVLNode(int value, AVLNode *left = nullptr, AVLNode *right = nullptr)
  {
    this->value = value;
    this->left = left;
    this->right = right;
  };

  ~AVLNode() {};
};

#endif // AVLNODE_H_INCLUDED
