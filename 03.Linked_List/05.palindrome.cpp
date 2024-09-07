// Implement a function to check if a linked list is a palindrome.
#include<iostream>
#include<stack>
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

Node *reverseList(Node *head){
    Node *curr = head;
    Node *prev = nullptr;

    while (curr != nullptr){
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}

Node* copyList(Node *head) {
    if (head == nullptr) return nullptr;

    Node *newHead = new Node();
    newHead->data = head->data;
    newHead->next = nullptr;
    Node *newList = newHead;
    Node *temp = head->next;

    while (temp != nullptr) {
        Node *newNode = new Node();
        newNode->data = temp->data;
        newNode->next = nullptr;
        newList->next = newNode;
        newList = newNode;
        temp = temp->next;
    }

    return newHead;
}

void isPalindromeWithReverse(Node *list) {
    // Make a copy of the original list
    Node *copy = copyList(list);
    Node *reverse = reverseList(copy);  // Reverse the copied list

    Node *runner = list;
    while (runner != nullptr && reverse != nullptr) {
        if (runner->data != reverse->data) {
            cout << "Not Palindrome" << endl;
            return;
        }
        reverse = reverse->next;
        runner = runner->next;
    }

    cout << "Palindrome" << endl;
}

void isPalindromeWithIteration(Node *head){
    Node *fast = head;
    Node *slow = head;
    stack <int> stk;
    while(fast!=nullptr && fast->next != nullptr){
        stk.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }

    // linked list length could be odd, so need to skip the middle item
    if(fast != nullptr){
        slow = slow->next;
    }

    while(slow != nullptr){
        int top = stk.top();
        if(slow->data !=top){
            cout << "Not Palindrome" << endl;
        }
        stk.pop();
        slow = slow->next;
    }

    cout << "Palindrome" << endl;
}


int main(){
    cout << "Create a linked list" << endl;
    Node *head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    isPalindromeWithIteration(head);
    isPalindromeWithReverse(head);
}