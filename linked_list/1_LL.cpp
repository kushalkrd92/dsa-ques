#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};

void insertAtBegin(Node* &head, Node* &tail, int data){
  Node* newptr = new Node(data);
  if(tail == NULL){
    tail = newptr;
    head = newptr;
    return;
  }
  newptr->next = head;
  head = newptr;
}

void insertAtEnd(Node* &head, Node* &tail, int data){
  Node* newptr = new Node(data);
  if(tail == NULL){
    tail = newptr;
    head = newptr;
    return;
  }
  tail->next = newptr;
  tail = newptr;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int pos){
  if(tail == NULL){
    Node* newptr = new Node(data);
    tail = newptr;
    head = newptr;
    return;
  }
  Node* temp = head;
  int count = 1;
  while(count < pos - 1){
    temp = temp->next;
    count++;
  }

  if(count == 1){
    insertAtBegin(head, tail, data);
    return;
  }
  else if(temp->next == NULL){
    insertAtEnd(head, tail, data);
    return;
  }
  Node* newNode = new Node(data);
  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteBegin(Node* &head){
  if(head == NULL)
    return;
  Node* temp = head;
  head = head->next;
  temp->next = NULL;
  delete temp;
}

void deleteEnd(Node* &head, Node* &tail){
  if(head == NULL)
    return;
  Node* curr = head;
  Node* prev = NULL;
  while(curr->next != NULL){
    prev = curr;
    curr = curr->next;
  }
  prev->next = NULL;
  delete curr;
  tail = prev;
}

void deleteNodeAtPosition(Node* &head, Node* &tail, int pos){
  if(head == NULL)
    return;
  if(pos == 1){
    deleteBegin(head);
    return;
  }
  Node* curr = head;
  Node* prev = NULL;
  int count = 1;
  while(count < pos && curr != NULL){
    prev = curr;
    curr = curr->next;
    count++;
  }

  if(curr->next == NULL){
    deleteEnd(head, tail);
    return;
  }
  else if(curr == NULL)
    return;
  prev->next = curr->next;
  curr->next = NULL;
  delete curr;
}

void deleteNodeValue(Node* &head, Node* &tail, int data){
  if(head == NULL)
    return;
  Node* curr = head;
  Node* prev = NULL;
  int count = 1;
  while(curr->data != data && curr != NULL){
    prev = curr;
    curr = curr->next;
    count++;
  }
  if(count == 1){
    deleteBegin(head);
    return;
  }
  if(curr->next == NULL){
    deleteEnd(head, tail);
    return;
  }
  prev->next = curr->next;
  curr->next = NULL;
  delete curr;
}

// print nodes
void traverse(Node* head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

int main(){
  Node *head = NULL;
  Node *tail = NULL;
  insertAtEnd(head, tail, 10);
  insertAtEnd(head, tail, 20);
  insertAtEnd(head, tail, 30);
  insertAtEnd(head, tail, 40);
  insertAtEnd(head, tail, 50);
  traverse(head);
  insertAtBegin(head, tail, -10);
  traverse(head);
  insertAtPosition(head, tail, -20, 1);
  traverse(head);
  insertAtPosition(head, tail, 60, 8);
  traverse(head);
  insertAtPosition(head, tail, 25, 5);
  traverse(head);
  insertAtPosition(head, tail, 35, 7);
  traverse(head);

  deleteBegin(head);
  traverse(head);
  deleteEnd(head, tail);
  traverse(head);
  deleteNodeAtPosition(head, tail, 1);
  traverse(head);
  deleteNodeAtPosition(head, tail, 7);
  traverse(head);
  deleteNodeAtPosition(head, tail, 4);
  traverse(head);
  deleteNodeValue(head, tail, 10);
  traverse(head);
  deleteNodeValue(head, tail, 40);
  traverse(head);
  deleteNodeValue(head, tail, 25);
  traverse(head);
  return 0;
}