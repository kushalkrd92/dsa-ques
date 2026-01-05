#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *next, *prev;
    Node(int data){
      this->data = data;
      this->next = this;
      this->prev = this;
    }
};

void insertAtEnd(Node* &head, Node* &tail, int data){
  Node* newNode = new Node(data);
  if(head == NULL){
    head = tail = newNode;
    return;
  }
  newNode->prev = tail;
  tail->next = newNode;
  tail = newNode;
  tail->next = head;
  head->prev = tail;
}

void traverse(Node* head){
  if(head == NULL)
    return;
    Node* temp = head;
    do{
      cout<<temp->data<<" ";
      temp = temp->next;
    }while(temp != head);
    cout<<endl;
}

// detect loops
bool detectLoop(Node* head){
  Node* slow, *fast;
  slow = fast = head;
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast)
      return true;
  }
  return false;
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
  cout<<detectLoop(head)<<endl;
  return 0;
}