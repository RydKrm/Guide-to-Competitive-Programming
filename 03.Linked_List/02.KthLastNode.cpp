// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

#include<iostream>
#include<map>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int list_size = 0;

Node* CreateNode(int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insert(Node *&head, int data){
    Node *newNode = CreateNode(data);
    list_size++;
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

// If the size is known then just iterate to the kth position
void kthNodeWithSizeKnow(Node *head){
    Node *temp = head;
    int cnt = 0;
    while(temp != head){
        cnt++;
        if(cnt == list_size){
            cout << "Data => " << temp->data << endl;
            break;
        }
        cnt++;
    }
}

// this will be recursive program to that. In the forward calls just called to the next position 
// after the backward calls increase the index number
// when index == k then find the position
void KthNode(Node *head,int k, int &index){
    Node *runner = head;
    runner = runner->next;
    if(runner== nullptr)
        return;
    KthNode(runner,k, index);
    index++;
    if(k==index){
        cout << runner->data << endl;
        return;
    }
}

// Two pointer runner methods
// take two pointer and point two to start position
// first pointer will iterate k time to positioned at kth item 
// now second pointer point to the head and start iteration. 
// in every iteration, first and second both pointer step one state forward
// So when the first pointer point in the end of list, second pointer will point the last kth item 
void KthItemWithTwoPointer(Node *head,int k){
    Node *runner1 = head;
    Node *runner2 = head;
    for (int i = 0; i < k;i++){
        runner1 = runner1->next;
    }
    while(runner1 != nullptr){
        runner1 = runner1->next;
        runner2 = runner2->next;
    }
    cout << k << "th position item " << runner2->data << endl;
}


int main(){
    cout << "Create a linked list" << endl;
    Node *head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);


    printList(head);
    int index = 0;
    KthNode(head, 3, index);
    KthItemWithTwoPointer(head, 3);
}