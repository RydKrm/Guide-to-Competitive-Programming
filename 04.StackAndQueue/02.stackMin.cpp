#include<iostream>
#include<queue>
using namespace std;

class Stack {
private:
    int *stack;
    int capacity;    
    int topIndex;
    int mn = INT_MAX;
    queue<int> min_queue;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        stack = new int[capacity];  
        topIndex = -1;               
    }

    ~Stack() {
        delete[] stack;
    }

    void push(int data) {
        if (topIndex == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        if(data<mn){
            min_queue.push(data);
            mn = data;
        }
        stack[++topIndex] = data;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        if(stack[topIndex]==min_queue.front()){
            min_queue.pop();
        }
        topIndex--;
    }
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;  
        }
        return stack[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int find_min(){
        return min_queue.front();
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack contents: ";
        for (int i = 0; i <= topIndex; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    //  Define the size of the stack
    // int n;
    // cout << "Enter the size of the stack: ";
    // cin >> n;
    Stack stack(12);

    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);

    stack.printStack();
    cout << "Top element: " << stack.top() << endl;
    stack.pop();
    stack.printStack();
    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
    return 0;
}
