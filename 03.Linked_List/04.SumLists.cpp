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

void insertFirst(Node*& head, int data){
    Node *newNode = CreateNode(data);
    if(head == nullptr){
        head = newNode;
        return;
    }
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

void summation(Node *&list1, Node *&list2, Node *&ans){
    Node *runner1 = list1;
    Node *runner2 = list2;
    int carry = 0;
    while(runner1!=nullptr && runner2 != nullptr){
        int sum = runner1->data + runner2->data + carry;
        carry = sum / 10;
        sum %= 10;
        insertFirst(ans, sum);
        runner1 = runner1->next;
        runner2 = runner2->next;
    }
    while(runner1 != nullptr){
        cout << "test 1" << endl;
        int sum = (runner1->data + carry) % 10;
        insertFirst(ans, sum);
        carry = (carry + runner1->data) / 10;
        runner1 = runner1->next;
    }
    while(runner2 != nullptr){
        cout << "test 02" << endl;
        int sum = (runner2->data + carry) % 10;
        insertFirst(ans, sum);
        carry = (carry + runner2->data)/10;
        runner2 = runner2->next;
    }
    if(carry){
        insertFirst(ans, carry);
    }
}


int main(){
    cout << "Create a linked list" << endl;
    Node *list1 = nullptr;
    insert(list1, 1);
    insert(list1, 2);
    insert(list1, 3);
    insert(list1, 4);
    insert(list1, 9);
    Node *list2 = nullptr;
    insert(list2, 5);
    insert(list2, 5);
    insert(list2, 2);
    insert(list2, 6);

    cout << "first list" <<endl;
    printList(list1);
    cout << "Second list" <<endl;
    printList(list2);
    cout << "After summation "<< endl;
    Node *sum = nullptr;
    summation(list1,list2,sum);
    printList(sum);
}