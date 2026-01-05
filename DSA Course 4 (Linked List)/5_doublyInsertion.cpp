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
};

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

void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail == NULL){
        Node* node = new Node(data);
        tail = node;
        head = node;
        return;
    }
    Node* temp = new Node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int data){
    if(head == NULL){
        Node* node = new Node(data);
        head = node; 
        tail = node;
        return;
    }

    if(pos == 1){
        insertAtHead(head,tail, data);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(head, tail, data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
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

void traverse(Node* head, Node* tail){
    Node* temp = head;
    while(temp != NULL){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
    std::cout<<"\thead: "<<head->data<<", tail: "<<tail->data<<std::endl;
}

int main(){
    // Node* node = new Node(4);
    // Node* head = node;
    // Node* tail = node;
    Node* head = NULL; 
    Node* tail = NULL;
    // traverse(head);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 0);
    traverse(head, tail);
    std::cout<<"\tNo. of nodes: "<<getLength(head)<<std::endl;

    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 7);
    traverse(head, tail);
    std::cout<<"\tNo. of nodes: "<<getLength(head)<<std::endl;

    insertAtPosition(head, tail, 3, 2);
    traverse(head, tail);
    std::cout<<"\tNo. of nodes: "<<getLength(head)<<std::endl;

    insertAtPosition(head, tail, 8, 8);
    traverse(head, tail);
    std::cout<<"\tNo. of nodes: "<<getLength(head)<<std::endl;

    insertAtPosition(head, tail, 1, -1);
    traverse(head, tail);
    std::cout<<"\tNo. of nodes: "<<getLength(head)<<std::endl;

    insertAtPosition(head, tail, 6, 4);
    traverse(head, tail);
    std::cout<<"\tNo. of nodes: "<<getLength(head)<<std::endl;
    return 0;
}