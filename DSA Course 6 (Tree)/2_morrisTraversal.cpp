#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int x)
  {
    data = x;
    left = right = nullptr;
  }
};

vector<int> inorderMorris(Node *root)
{
  vector<int> result;
  Node *curr = root;

  while (curr != nullptr)
  {
    if (curr->left)
    {
      Node *pred = curr->left;
      while (pred->right && pred->right != curr)
        pred = pred->right;
      if (pred->right == NULL)
      {
        pred->right = curr;
        curr = curr->left;
      }
      else
      {
        pred->right = NULL;
        result.push_back(curr->data);
        curr = curr->right;
      }
    }
    else
    {
      result.push_back(curr->data);
      curr = curr->right;
    }
  }
  return result;
}

int main()
{

  // Representation of input binary tree:
  //           1
  //          / \
    //         2   3
  //            / \  
    //           4   5
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->right->left = new Node(4);
  root->right->right = new Node(5);

  vector<int> result = inorderMorris(root);

  for (int data : result)
  {
    cout << data << " ";
  }

  return 0;
}