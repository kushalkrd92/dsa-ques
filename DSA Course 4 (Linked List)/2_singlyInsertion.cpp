#include<iostream>

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertionAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertionAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void insertionAtPosition(Node* &head, Node* &tail, int pos, int data){
    if(head == NULL){
        Node* node = new Node(data);
        head = node;
        tail = node;
        return;
    }
    if(pos == 1){
        insertionAtHead(head, data);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertionAtTail(tail, data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

bool isCircular(Node* head){
    if(head == NULL)
        return true;
    if(head->next == NULL)
        return true;
    Node* temp = head->next;
    while(temp != NULL && temp != head)
        temp = temp->next;
    if(temp == NULL)
        return false;
    return true;
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
    Node* head = NULL;
    Node* tail = NULL;
    Node* node = new Node(10);
    head = node;
    tail = node;
    traverse(head);
    insertionAtHead(head, 20); 
    insertionAtHead(head, 30); 
    insertionAtHead(head, 40); 
    traverse(head);

    traverse(head);
    insertionAtTail(tail, 20); 
    insertionAtTail(tail, 30); 
    insertionAtTail(tail, 40); 
    traverse(head);

    insertionAtPosition(head, tail, 8, 2);
    traverse(head);
    insertionAtPosition(head, tail, 1, 12);
    traverse(head);
    insertionAtPosition(head, tail, 5, 32);
    traverse(head);
    bool ans = isCircular(head);
    if(ans)
        std::cout<<"List is circular"<<std::endl;
    else
        std::cout<<"List is not circular"<<std::endl;
    return 0;
}