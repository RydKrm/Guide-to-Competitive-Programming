// Describe how you could use a single array to implement three stacks.
#include<iostream>
using namespace std;

    // First take the size of the stack
    // Divide the size into three part,
    // First part will be 0 to n/3
    // Second part will be n/3+1 to 2n/3
    // Third part will be 2n/3+1 to n
    // to do all the stack method need to tell from which part do you want to access


class Stack{
private:
    int *stack;
    int capacity;
    int topIndex1,topIndex2,topIndex3;

public:
    Stack(int capacity){
        this->capacity = capacity;
        stack = new int[capacity];
        topIndex1 = -1;
        topIndex2 = capacity / 3 - 1;
        topIndex3 = 2*(capacity/3) - 1;
    }

    ~Stack(){
        delete[] stack;
    }

    void pushHelper(int data,int &ind,int cap){
        if(ind==cap-1){
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++ind] = data;
    }

    void push(int data, int stackNum){
        if(stackNum == 1){
            pushHelper(data, topIndex1, capacity / 3);
        } else if(stackNum == 2){
            pushHelper(data, topIndex2, (2 * capacity) / 3);
        } else {
            pushHelper(data, topIndex3, capacity);
        }
    }

    bool isEmpty(int stackNumber){
        if(stackNumber==1){
            return topIndex1 == -1;
        } else if(stackNumber == 2){
            return topIndex2 == capacity / 3 - 1;
        } else{
            return topIndex3 == (2 * capacity) / 3 -1;
        }
    }

    void pop(int stackNum){
        if(isEmpty(stackNum)) {
            cout << "Stack "<<stackNum<<" underflow" << endl;
            return;
        }
        if(stackNum==1){
            topIndex1--;
        } else if(stackNum == 2){
            topIndex2--;
        } else {
            topIndex3--;
        }
    }

    int top(int stackNum){
        if(isEmpty(stackNum)) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        if(stackNum == 1){
            return stack[topIndex1];
        } else if(stackNum == 2){
            return stack[topIndex2];
        } else {
            return stack[topIndex3];
        }
    }

    void printStack(int stackNum){
        if(isEmpty(stackNum)){
            cout << "Stack is empty" << endl;
            return;
        }
        int start = 0, end = capacity;
        if(stackNum == 1){
            start = 0;
            end = topIndex1;
        } else if(stackNum == 2){
            start = capacity / 3;
            end = topIndex2;
        } else{
            start = (2 * capacity) / 3;
            end = topIndex3;
        }
        for (int i = start; i <= end;i++){
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    void fullPrint(){
        for (int i = 0; i < capacity;i++){
            cout<<stack[i] << " " << endl;
        }
        cout << endl;
    }

};

int main() {
    // int n;
    // cout << "Enter the size of the stack: ";
    // cin >> n;

    // Create a Stack object with the given size
    Stack stack(12);

    // Push elements onto the stack
    stack.push(1,1);
    stack.push(2,1);

    stack.push(3,2);
    stack.push(4,2);

    stack.push(5,3);
    stack.push(6,3);
    stack.push(7,3);

    // Print the current stack
    cout << "print stack - 1 " << endl;
    stack.printStack(1);
    cout << "print stack - 2 " << endl;
    stack.printStack(2);
    cout << "print stack - 3 " << endl;
    stack.printStack(3);

    // Peek at the top element
    cout << "Top element of stack - 1: " << stack.top(1) << endl;
    cout << "Top element of stack - 2: " << stack.top(2) << endl;
    cout << "Top element of stack - 3: " << stack.top(3) << endl;

    // Pop an element from the stack
    stack.pop(1);
    stack.pop(2);
    stack.pop(3);

    // Print the stack after popping
    cout << "print stack - 1 " << endl;
    stack.printStack(1);
    cout << "print stack - 2 " << endl;
    stack.printStack(2);
    cout << "print stack - 3 " << endl;
    stack.printStack(3);
    cout << "Full print" << endl;
    stack.fullPrint();
    // Check if the stack is empty
    if (stack.isEmpty(1)) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}
