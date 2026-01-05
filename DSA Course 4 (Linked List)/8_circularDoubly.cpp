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
            std::cout<<"Node: "<<value<<" deleted"<<std::endl;
        }
};

void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        std::cout<<"Empty List"<<std::endl;
        return;
    }
    Node* prev = tail;
    Node* curr = tail->next;
    while(curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    // 1 node
    if(curr == prev){
        tail = NULL;
        return;
    }
    // >1 node
    prev->next = curr->next;
    if(tail == curr){
        tail = curr->next;
    }
    curr->next = NULL;
    delete curr;
}

void insertNode(Node* &tail, int element, int data){
    if(tail == NULL){
        Node* node = new Node(data);
        node->next = node;
        node->prev = node;
        tail = node;
        return;
    }
    if(tail->next == tail){
        Node* temp = new Node(data);
        temp-> prev = tail;
        temp-> next = tail;
        tail->next = temp;
        tail->prev = temp;
        return;
    }
    Node* curr = tail;
    while(curr->data != element){
        curr = curr->next;
    }
    Node* temp = new Node(data);
    temp->next = curr->next;
    temp->prev = curr;
    curr->next->prev = temp;
    curr->next = temp;
}

void traverse(Node* tail){
    if(tail == NULL){
        std::cout<<"Empty List "<<std::endl;
        return;
    }
    Node* temp = tail;
    do{
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);
    std::cout<<std::endl;
}


int main(){
    Node* tail = NULL;
    traverse(tail);
    insertNode(tail, 4, 1);
    traverse(tail);
    insertNode(tail, 1, 2);
    traverse(tail);
    insertNode(tail, 2, 3);
    traverse(tail);
    insertNode(tail, 3, 4);
    traverse(tail);
    insertNode(tail, 4, 5);
    traverse(tail);
    insertNode(tail, 5, 6);
    traverse(tail);
    insertNode(tail, 6, 7);
    traverse(tail);
    deleteNode(tail, 5);
    traverse(tail);
    deleteNode(tail, 3);
    traverse(tail);
    deleteNode(tail, 1);
    traverse(tail);
    deleteNode(tail, 2);
    traverse(tail);
    return 0;
}