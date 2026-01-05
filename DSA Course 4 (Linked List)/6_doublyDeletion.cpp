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

void deleteFirst(Node* &head){
    if(head == NULL){
        std::cout<<"Empty"<<std::endl;
        return;
    }
    Node* temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
}

void deleteLast(Node* &head, Node* &tail){
    if(head == NULL){
        std::cout<<"Empty"<<std::endl;
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    curr->prev = NULL;
    prev->next = NULL;
    curr->next = NULL;
    delete curr;

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    tail = temp;
}

void deletePosition(Node* &head, Node* &tail, int pos){
    if(head == NULL){
        std::cout<<"Empty"<<std::endl;
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    while(cnt < pos){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    prev->next = curr->next;
    curr->next->prev = prev;
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    tail = temp;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* node = new Node(data);
        head = node; 
        tail = node;
        return;
    }
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

int getLength(Node* head){
    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void traverse(Node* head, Node* tail){
    if(head == NULL){
        std::cout<<"Empty"<<std::endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
    std::cout<<"\tNo. of nodes: "<<getLength(head)<<std::endl;
    std::cout<<"\thead: "<<head->data<<", tail: "<<tail->data<<std::endl;
}

int main(){
    Node* head = NULL; 
    Node* tail = NULL;
    traverse(head, tail);
    insertAtHead(head, tail, 88);
    insertAtHead(head, tail, 77);
    insertAtHead(head, tail, 66);
    insertAtHead(head, tail, 44);
    insertAtHead(head, tail, 55);
    insertAtHead(head, tail, 44);
    insertAtHead(head, tail, 33);
    insertAtHead(head, tail, 22);
    insertAtHead(head, tail, 11);
    traverse(head, tail);
    deleteFirst(head);
    traverse(head, tail);
    deleteLast(head, tail);
    traverse(head, tail);
    deletePosition(head, tail, 5);
    traverse(head, tail);
    return 0;
}