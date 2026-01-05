#include <iostream>
using namespace std;

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

void insertAtEnd(Node* &head, Node* &tail, int data){
  Node* newNode = new Node(data);
  if(head == NULL){
    tail = head = newNode;
    return;
  }
  newNode->prev = tail;
  tail->next = newNode;
  tail = newNode;
}

void traverse(Node* head){
  if(head == NULL)
    return;
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

int main(){
  Node* head = NULL;
  Node* tail = NULL;
  insertAtEnd(head, tail, 10);
  insertAtEnd(head, tail, 20);
  insertAtEnd(head, tail, 30);
  insertAtEnd(head, tail, 40);
  insertAtEnd(head, tail, 50);
  traverse(head);
  return 0;
}