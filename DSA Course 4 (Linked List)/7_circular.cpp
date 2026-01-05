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
            std::cout<<"Node: "<<value<<" deleted"<<std::endl;
        }
};

void insertNode(Node* &tail, int element, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        temp->next = temp;
        tail = temp;
        return;
    }
    if(tail->next == tail){
        Node* temp = new Node(data);
        temp->next = tail;
        tail->next = temp;
        return;
    }

    Node* curr = tail;
    while(curr->data != element){
        curr = curr->next;
    }
    Node* temp = new Node(data);
    temp->next = curr->next;
    curr->next = temp;
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        std::cout<<"Empty List "<<std::endl;
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
    prev->next = curr->next;
    if(tail == curr){
        tail = curr->next;
    }
    curr->next = NULL;
    delete curr;
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
    insertNode(tail, 1, 1);
    traverse(tail);
    insertNode(tail, 1, 3);
    traverse(tail);
    insertNode(tail, 3, 4);
    traverse(tail);
    insertNode(tail, 4, 5);
    traverse(tail);
    insertNode(tail, 1, 2);
    traverse(tail);
    insertNode(tail, 5, 6);
    traverse(tail);
    deleteNode(tail, 3);
    traverse(tail);
    deleteNode(tail, 2);
    traverse(tail);
    deleteNode(tail, 1);
    traverse(tail);
    deleteNode(tail, 6);
    traverse(tail);
    bool ans = isCircular(tail);
    if(ans)
        std::cout<<"List is circular"<<std::endl;
    else
        std::cout<<"List is not circular"<<std::endl;
    return 0;
}