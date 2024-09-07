// write code to remove duplicates from an unsorted linked list. 
// FOLLOW UP How would you solve this problem if a temporary buffer is not allowed?

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

// Remove duplicate using hashmap
// Create a hashmap and iterate through the list. Every iteration check item already exists in the map or not 
// if exists then delete item from list 
// if not exists then add it to the map
void removeDupWithHash(Node *&head){
    map<int, int> checker;
    Node *temp = head;
    Node *prev = nullptr;
    while(temp != nullptr){
        if(checker.count(temp->data)){
            cout << temp->data << endl;
            prev->next = temp->next;
        }else{
            checker[temp->data]++;
        }
        prev = temp;
        temp = temp->next;
    }
}

// need two nested loop to do this. It will take O(n^2) complexity. it's a two pointer method
// first pointer will point to a node and another point will iterate through the list and check for match 
// with first pointer data if match remove it from the list
void removeDupWithoutHash(Node *&head){
    Node *runner1 = head;
    while(runner1!=nullptr){
        Node *runner2 = head;
        Node *prev = nullptr;
        while(runner2!=nullptr){
            if(runner2->data == runner1->data && runner2->next != runner1->next){
                prev->next = runner2->next;
            }
            prev = runner2;
            runner2 = runner2->next;
        }
        runner1 = runner1->next;
    }
}

int main(){
    cout << "Create a linked list" << endl;
    Node *head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 5);
    insert(head, 3);
    insert(head, 5);
    insert(head, 2);
    insert(head, 4);
    insert(head, 5);
    insert(head, 2);
    insert(head, 6);
    insert(head, 2);
    cout << "Before the remove" << endl;
    printList(head);
    removeDupWithoutHash(head);
    cout << "After the remove" << endl;
    printList(head);
}