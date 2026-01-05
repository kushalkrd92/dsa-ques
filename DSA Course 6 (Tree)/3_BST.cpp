#include <iostream>
#include <queue>

class Node{
  public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
      this->data = d;
      this->left = this->right = NULL;
    }
};

Node* minVal(Node* root){
  Node* temp = root;
  while(temp->left != NULL)
    temp = temp->left;
  return temp;
}

Node* maxVal(Node* root){
  Node* temp = root;
  while(temp->right != NULL)
    temp = temp->right;
  return temp;
}

Node* deleteNode(Node* root, int d){
  if(root == NULL)
    return NULL;
  if(root->data == d){
    // 0 child
    if(root->left == NULL && root->right == NULL){
      delete root;
      return NULL;
    }
    // 1 child
    // left child exists
    if(root-> left && root->right == NULL){
      Node* temp = root->left;
      delete root;
      return temp;
    }
    // right child exists
    if(root-> left == NULL && root->right){
      Node* temp = root->right;
      delete root;
      return temp;
    }
    // 2 childs
    if(root->left && root->right){
      int mini = minVal(root->right)->data;
      root->data = mini;
      root->right = deleteNode(root->right, mini);
      return root;
    }
  }
  else if(root->data > d)
    root->left = deleteNode(root->left, d);
  else  
    root->right = deleteNode(root->right, d);
  return root;
}

Node* inorderPredecessor(Node* root, int key){
  if(root == NULL)
    return NULL;
  if(root->data == key){
    Node* temp = maxVal(root->left);
    return temp;
  }
  else if(root->data > key)
    root->left = inorderPredecessor(root->left, key);
  else  
    root->right = inorderPredecessor(root->right, key);
  return root;
}

Node* inorderSuccessor(Node* root, int key){
  if(root == NULL)
    return NULL;
  if(root->data == key){
    Node* temp = minVal(root->right);
    return temp;
  }
  else if(root->data > key)
    root->left = inorderSuccessor(root->left, key);
  else  
    root->right = inorderSuccessor(root->right, key);
  return root;
}

Node* insertionBST(Node* root, int d){
  if(root == NULL){
    root = new Node(d);
    return root;
  }
  if(d > root->data)
    root->right = insertionBST(root->right, d);
  else
    root->left = insertionBST(root->left, d);
  return root;
}

void takeInput(Node* &root){
  int d;
  std::cout<<"Enter data: ";
  std::cin>>d;
  while(d != -1){
    root = insertionBST(root, d);
    std::cin>>d;
  }
}

void levelOrderTraversal(Node* root){
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            std::cout<<std::endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            std::cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

void inOrder(Node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    std::cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root){
    if(root == NULL)
        return;
    std::cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout<<root->data<<" ";
}

int main(){
  Node* root = NULL;
  takeInput(root);
  std::cout<<"Level Order Traversal: "<<std::endl;
  levelOrderTraversal(root);
  std::cout<<"Inorder Traversal: "<<std::endl;
  inOrder(root);
  std::cout<<std::endl;
  std::cout<<"Preorder Traversal: "<<std::endl;
  preOrder(root);
  std::cout<<std::endl;
  std::cout<<"Postorder Traversal: "<<std::endl;
  postOrder(root);
  std::cout<<std::endl;
  std::cout<<"Max value is: "<<maxVal(root)->data<<std::endl;
  std::cout<<"Min value is: "<<minVal(root)->data<<std::endl;
  root = deleteNode(root, 13);
  std::cout<<"Level Order Traversal: "<<std::endl;
  levelOrderTraversal(root);
  std::cout<<"Inorder Traversal: ";
  inOrder(root);
  std::cout<<std::endl;
  std::cout<<"Inorder Predecessor of 10 is: "<<inorderPredecessor(root, 10)->data<<std::endl;
  std::cout<<"Inorder Predecessor of 10 is: "<<inorderSuccessor(root, 10)->data<<std::endl;
  return 0;
}

// 10 5 12 3 6 14 -1