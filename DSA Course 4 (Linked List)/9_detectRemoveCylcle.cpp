#include<iostream>
#include<map>

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

bool detectLoopUsingMap(Node* &head){
    std::map<Node*, bool> visited;
    Node* temp = head;
    while(temp != NULL){
        if(visited[temp]==true){
            std::cout<<"Starting Loop Node: "<<temp->data<<std::endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// using floyd cycle detection algorithm
bool detectCycle(Node* &head){
    if(head == NULL)
        return false;
    Node* fast = head;
    Node* slow = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if(fast == NULL)
            return false;
        if(slow == fast){
            std::cout<<"Intersection Node: "<<slow->data<<std::endl;
            return true;
        }
    }
    return false;
}

Node* floydDetectCycle(Node* &head){
    if(head == NULL)
        return NULL;

    Node* fast = head;
    Node* slow = head;
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if(slow == fast)
            return slow;
        if(fast == NULL)
            return NULL;
    }
    return NULL;
}

Node* startingLoopNode(Node* &head){
    Node* intersection = floydDetectCycle(head);
    if(intersection == NULL)
        return NULL;
    Node* slow = head;
    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeLoop(Node* &head){
    Node* startingNode = startingLoopNode(head);
    if(startingNode == NULL)
        return;
    Node* temp = startingNode;
    while(temp->next != startingNode)
        temp = temp->next;
    temp->next = NULL;
}


void insertionAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void traverse(Node* head){
    if(head == NULL){
        std::cout<<"Empty List"<<std::endl;
        return;
    }
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
    insertionAtHead(head, tail, 60);
    insertionAtHead(head, tail, 50);
    insertionAtHead(head, tail, 40);
    insertionAtHead(head, tail, 30);
    insertionAtHead(head, tail, 20);
    insertionAtHead(head, tail, 10);

    tail->next = head->next;
    
    std::cout<<"Head: "<<head->data<<std::endl;
    std::cout<<"Tail: "<<tail->data<<std::endl;

    // if(detectLoopUsingMap(head))
    //     std::cout<<"Cycle present."<<std::endl;
    // else   
    //     std::cout<<"Cycle not present."<<std::endl;

    if(detectCycle(head))
        std::cout<<"Cycle present."<<std::endl;
    else   
        std::cout<<"Cycle not present."<<std::endl;
    std::cout<<"Start Loop node: "<<startingLoopNode(head)->data<<std::endl;

    removeLoop(head);
    traverse(head);

    return 0;
}