// Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and is Empty.

#include<iostream>
#include<stack>
using namespace std;

stack<int> sortStack(stack<int> stk){
    stack<int> output, temp;
    while(!stk.empty()){
        int top = stk.top();
        stk.pop();
        while(!output.empty() && output.top()<=top){
            int out_top = output.top();
            temp.push(out_top);
            output.pop();
        }
        output.push(top);
        while(!temp.empty()){
            int temp_push = temp.top();
            output.push(temp_push);
            temp.pop();
        }
    }
    return output;
}

int main(){
    stack<int> stk;
    stk.push(2);
    stk.push(5);
    stk.push(3);
    stk.push(7);
    stk.push(12);
    stk.push(13);
    stk.push(4);
    stk.push(8);
    stk.push(2);
    stk = sortStack(stk);
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
}