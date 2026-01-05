#include<iostream>
#include<queue>

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

node* builtTree(node* &root){
    std::cout<<"Enter data: "<<std::endl;
    int data;
    std::cin>>data;
    root = new node(data);
    if(data == -1)
        return NULL;
    std::cout<<"Enter data for left child of "<<root->data<<" : "<<std::endl;
    root->left = builtTree(root->left);
    std::cout<<"Enter data for right child of "<<root->data<<" : "<<std::endl;
    root->right = builtTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    std::queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
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

void builtTreeFromLevelOrder(node* &root){
    std::queue<node*> q;
    std::cout<<"Enter data for the root: ";
    int data;
    std::cin>>data;
    root = new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        std::cout<<"Enter data for the left child of "<<temp->data<<": ";
        int leftData;
        std::cin>>leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        std::cout<<"Enter data for the right child of "<<temp->data<<": ";
        int rightData;
        std::cin>>rightData;
        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void inOrder(node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    std::cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(node* root){
    if(root == NULL)
        return;
    std::cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout<<root->data<<" ";
}

void countLeafNodes(node* root, int &count){
    if(root == NULL)
        return;
    countLeafNodes(root->left, count);
    if(root->left == NULL && root->right == NULL)
        count++;
    countLeafNodes(root->right, count);
}

int main(){
    node* root;
    // builtTree(root);
    builtTreeFromLevelOrder(root);
    std::cout<<std::endl;
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
    int count = 0;
    countLeafNodes(root, count);
    std::cout<<"No. of leaf nodes: "<<count<<std::endl;
    return 0;
}

// built tree -> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// built tree from level order -> 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1