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
    if (hasNoChildren())
    {
      balanceFactor = 0;
    }
    else if (hasLeftChildOnly())
    {
      balanceFactor = left->height + 1;
    }
    else if (hasRightChildOnly())
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
    if (hasNoChildren())
    {
      height = 0;
    }
    else if (hasLeftChildOnly())
    {
      height = left->height + 1;
    }
    else if (hasRightChildOnly())
    {
      height = right->height + 1;
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

  bool hasNoChildren()
  {
    return right == nullptr && left == nullptr;
  }

  bool hasLeftChildOnly()
  {
    return left != nullptr && right == nullptr;
  }

  bool hasRightChildOnly()
  {
    return right != nullptr && left == nullptr;
  }
};

#endif // AVLNODE_H_INCLUDED
