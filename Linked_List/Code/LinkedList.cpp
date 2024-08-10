#include<iostream>
#include<stdio.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

// Create new Node
 Node* createNode(int data){
     Node *newNode = new Node();
     newNode->data = data;
     newNode->next = nullptr;
     return newNode;
 }

void insert(struct Node*& head, int data){
    Node *newNode = createNode(data);
    if (head == nullptr){
        head = newNode;
    } else{
        Node *temp = head;
        while(temp->next!= nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertFirst(Node*& head, int data){
    Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void printList(Node* head){
    Node *temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "Null " << endl;
}

void deleteNode(Node*& head,int pos){
    if(pos==1){
        cout << "Head cannot be deleted"<< endl;
        return;
    }
    pos--;
    int cnt = 1;
    Node *temp = head;
    while (temp != nullptr){
        if(cnt==pos){
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
        cnt++;
    }
    cout << "Position not found" << endl;
}

void reverseList(Node *& head){
    Node *curr = head;
    Node *prev = nullptr;

    while (curr != nullptr){
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

int main(){
    cout<<"Linked List"<<endl;
    Node *head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    printList(head);
    reverseList(head);
    cout << "After Reverse " << endl;
    printList(head);
    deleteNode(head,5);
    printList(head);
}