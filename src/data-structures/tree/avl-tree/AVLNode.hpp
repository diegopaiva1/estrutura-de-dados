#ifndef AVLNODE_H_INCLUDED
#define AVLNODE_H_INCLUDED

class AVLNode
{
public:
  int key;
  AVLNode *left;
  AVLNode *right;

  AVLNode(int key, AVLNode *left = nullptr, AVLNode *right = nullptr)
  {
    this->key = key;
    this->left = left;
    this->right = right;
  };

  ~AVLNode() {};

  int getBalanceFactor()
  {
    return height(left) - height(right);
  }

  int height(AVLNode *node)
  {
    if (node == nullptr)
    {
      return -1;
    }

    if (height(node->right) > height(node->left))
    {
      return height(node->right) + 1;
    }
    else
    {
      return height(node->left) + 1;
    }
  }
};

#endif // AVLNODE_H_INCLUDED
