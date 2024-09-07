// Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x

#include<iostream>
#include<map>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* CreateNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insert(Node *&head, int data){
    Node *newNode = CreateNode(data);
    if(head == nullptr){
        head = newNode;
    } else {
        Node *temp = head;
        while(temp ->next!= nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head){
    Node *temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "Null " << endl;
}

void partition(Node *head, int k){
    
    Node *before = nullptr;
    Node *after = nullptr;

    Node *runner = head;
    while(runner!=nullptr){
        if(runner->data<k){
            insert(before, runner->data);
        } else {
            insert(after, runner->data);
        }
        runner = runner->next;
    }

    // Merge two list together
    cout << "before first " <<before->data<< endl;
    runner = before;
    while(runner != nullptr){
        runner = runner->next;
    }
    Node *ref = before;
    cout << "after first " <<after->data<< endl;
    runner = after->next;

    while(ref != nullptr){
        cout << ref->data << " ";
        ref = ref->next;
    }
    cout << endl;
    
}



int main(){
    cout << "Create a linked list" << endl;
    Node *head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 5);
    insert(head, 2);
    insert(head, 6);
    insert(head, 8);
    insert(head, 7);
    insert(head, 12);


    printList(head);
    cout << "After Partition " << endl;
    partition(head, 5);
}