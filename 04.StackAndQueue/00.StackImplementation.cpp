#include<iostream>
using namespace std;

class Stack {
private:
    int *stack;      // Array to store stack elements
    int capacity;    // Maximum size of the stack
    int topIndex;    // Points to the current top element

public:
    // Constructor to initialize the stack with a given capacity
    Stack(int capacity) {
        this->capacity = capacity;
        stack = new int[capacity];   // Dynamically allocate memory for the stack
        topIndex = -1;               // Stack is initially empty
    }

    // Destructor to free dynamically allocated memory
    ~Stack() {
        delete[] stack;
    }

    // Push an element onto the stack
    void push(int data) {
        if (topIndex == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++topIndex] = data;
    }

    // Pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        topIndex--;
    }

    // Return the top element of the stack without removing it
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;  // Return -1 when the stack is empty
        }
        return stack[topIndex];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Print the contents of the stack
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
    // Define the size of the stack
    int n;
    cout << "Enter the size of the stack: ";
    cin >> n;

    // Create a Stack object with the given size
    Stack stack(n);

    // Push elements onto the stack
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);

    // Print the current stack
    stack.printStack();

    // Peek at the top element
    cout << "Top element: " << stack.top() << endl;

    // Pop an element from the stack
    stack.pop();

    // Print the stack after popping
    stack.printStack();

    // Check if the stack is empty
    if (stack.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
