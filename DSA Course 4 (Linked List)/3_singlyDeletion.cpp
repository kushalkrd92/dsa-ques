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

void insertionAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void deletionAtFirst(Node* &head){
    Node* temp = head;
    head = head->next;
    temp->next = NULL;    // only for our destructor
    delete temp;
}

void deletionAtEnd(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->next = NULL;    // only for our destructor
    delete curr;
}

void deletionAtPosition(Node* &head, int pos){
    if(pos == 1){
        deletionAtFirst(head);
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    int cnt = 1;
    while(cnt < pos){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    prev->next = curr->next;
    curr->next = NULL;   // only for our destructor
    delete curr;
}

void deleteValue(Node* &head, int value){
    if(head->data == value){
        deletionAtFirst(head);
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    while(curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;   // only for our destructor
    delete curr;
}

void traverse(Node* head){
    Node* temp = head;
    while(temp != NULL){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

int main(){
    Node* node = new Node(10);
    Node* head = node;
    Node* tail = node;
    insertionAtHead(head, 20); 
    insertionAtHead(head, 30); 
    insertionAtHead(head, 40); 
    insertionAtHead(head, 50); 
    insertionAtHead(head, 60); 
    insertionAtHead(head, 70); 
    traverse(head);
    deletionAtFirst(head);
    traverse(head);
    deletionAtEnd(head);
    traverse(head);
    deletionAtPosition(head, 3);
    traverse(head);
    deleteValue(head, 50);
    traverse(head);
    return 0;
}