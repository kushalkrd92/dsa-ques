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

// print nodes
void traverse(Node* head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

// count nodes
int countNodes(Node* head){
  Node* temp = head;
  int count = 0;
  while(temp != NULL){
    count++;
    temp = temp->next;
  }
  return count;
}

// print second last node
void secondLast(Node* head){
  if(head == NULL || head->next == NULL){
    cout<<-1<<endl;
    return;
  }
  Node* temp = head;
  while(temp->next->next != NULL){
    temp = temp->next;
  }
  cout<<temp->data<<endl;
}

// find key
void findElement(Node* head, int k){
  Node* temp = head;
  while(temp != NULL){
    if(temp->data == k){
      cout<<"YES"<<endl;
      return;
    }
    temp = temp->next;
  }
  cout<<"NO"<<endl;
}

// print alternate nodes
void printAlternate(Node* head){
  if(head == NULL)
    return;
  Node* temp = head;
  int count = 0;
  while(temp != NULL){
    if(count%2 == 0)
      cout<<temp->data<<" ";
    count++;
    temp = temp->next;
  }
  cout<<endl;
}

// print mid value
void printMid(Node* head){
  if(head == NULL)
    cout<<-1<<endl;
  Node* slow = head;
  Node* fast = head;
  while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  cout<<slow->data<<endl;
}

// reverse linked list
void reverse(Node* &head, Node* &tail){
  if(head == NULL || head->next == NULL)
    return; 

  tail = head;
  Node *curr, *prev, *temp;
  curr = head;
  prev = temp = NULL;
  while(curr != NULL){
    temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  head = prev;
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
  cout<<countNodes(head)<<endl;
  secondLast(head);
  findElement(head, 40);
  findElement(head, 90);
  printAlternate(head);
  
  printMid(head);
  insertAtEnd(head, tail, 100);
  traverse(head);
  printMid(head);

  reverse(head, tail);
  traverse(head);
  insertAtEnd(head, tail, 0);
  traverse(head);
  return 0;
}