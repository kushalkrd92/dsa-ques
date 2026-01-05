#include<iostream>

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void traverse(Node* head){
    Node* temp = head;
    while(temp != NULL){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

int getLength(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

int main(){
    Node* node = new Node(1);
    Node* head = node;
    Node* tail = node;
    traverse(head);
    std::cout<<"No. of nodes: "<<getLength(head)<<std::endl;
    return 0;
}