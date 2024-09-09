// Implement a MyQueue class which implements a queue using two stacks
#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> inputStack, outputStack;
    void transfer() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty()) {
            transfer(); 
        }
        int frontElement = outputStack.top();
        outputStack.pop();
        return frontElement;
    }

    int peek() {
        if (outputStack.empty()) {
            transfer(); 
        }
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);
    
    std::cout << "Front element: " << q.peek() << std::endl; 
    std::cout << "Pop: " << q.pop() << std::endl;      
    std::cout << "Front element: " << q.peek() << std::endl; 
    std::cout << "Pop: " << q.pop() << std::endl;             
    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << std::endl; 

    return 0;
}
