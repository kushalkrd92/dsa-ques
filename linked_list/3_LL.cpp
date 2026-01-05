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

// merge 2 sorted LL
Node* merge(Node* head1, Node* head2){
  if(head1 == NULL)
    return head2;
  if(head2 == NULL)
    return head1;
  
  Node* head = NULL;
  Node* tail = NULL;
  if(head1->data < head2->data){
    head = tail = head1;
    head1 = head1->next;
  }
  else{
    head = tail = head2;
    head2 = head2->next;
  }

  while(head1 != NULL && head2 != NULL){
    if(head1->data < head2->data){
      tail->next = head1;
      tail = head1;
      head1 = head1->next;
    }
    else{
      tail->next = head2;
      tail = head2;
      head2 = head2->next;
    }
  }
  if(head1 != NULL){
    tail->next = head1;
  }
  if(head2 != NULL){
    tail->next = head2;
  }
  return head;
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
  // list 1
  Node *head1 = NULL;
  Node *tail1 = NULL;
  insertAtEnd(head1, tail1, 10);
  insertAtEnd(head1, tail1, 20);
  insertAtEnd(head1, tail1, 30);
  insertAtEnd(head1, tail1, 40);
  insertAtEnd(head1, tail1, 50);
  traverse(head1);

  // list 2
  Node *head2 = NULL;
  Node *tail2 = NULL;
  insertAtEnd(head2, tail2, 15);
  insertAtEnd(head2, tail2, 25);
  insertAtEnd(head2, tail2, 35);
  traverse(head2);

  Node* head = merge(head1, head2);
  traverse(head);
  cout<<detectLoop(head)<<endl;
  return 0;
}