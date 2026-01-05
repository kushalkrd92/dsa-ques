#include<iostream>

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        ~Node(){
            int value = this->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
        }
};

int main(){
    Node* node = new Node(22);
    std::cout<<node->data<<std::endl;
    std::cout<<node->next<<std::endl;
    delete node;
    std::cout<<node->data<<std::endl;
    std::cout<<node->next<<std::endl;
    return 0;
}