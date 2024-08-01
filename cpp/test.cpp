#include<iostream>
#include<stdio.h>
using namespace std;

int sum(int a, int b=5){
    return a + b;
}

int main(){
    cout<<"Hello world!"<<endl;
    int s = sum(4);
    printf("sum => %d \n", s);
    return 0;
}