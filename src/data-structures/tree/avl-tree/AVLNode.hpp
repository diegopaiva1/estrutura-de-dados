#ifndef AVLNODE_H_INCLUDED
#define AVLNODE_H_INCLUDED

class AVLNode
{
public:
  int key;
  AVLNode *left;
  AVLNode *right;
  int height;
  int balanceFactor;

  AVLNode(int key)
  {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
    this->height = 0;
    this->balanceFactor = 0;
  };

  ~AVLNode() {};

  void updateBalanceFactor()
  {
    if (right == nullptr && left == nullptr)
    {
      balanceFactor = 0;
    }
    else if (left != nullptr && right == nullptr)
    {
      balanceFactor = left->height + 1;
    }
    else if (right != nullptr && left == nullptr)
    {
      balanceFactor = -(right->height + 1);
    }
    else
    {
      balanceFactor = left->height - right->height;
    }
  }

  void updateHeight()
  {
    if (left != nullptr && right == nullptr)
    {
      height = left->height + 1;
    }
    else if (right != nullptr && left == nullptr)
    {
      height = right->height + 1;
    }
    else if (right == nullptr && left == nullptr)
    {
      height = 0;
    }
    else
    {
      if (right->height > left->height)
      {
        height = right->height + 1;
      }
      else
      {
        height = left->height + 1;
      }
    }
  }
};

#endif // AVLNODE_H_INCLUDED
