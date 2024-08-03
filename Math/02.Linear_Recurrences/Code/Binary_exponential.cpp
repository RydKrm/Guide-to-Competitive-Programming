#include<iostream>
using namespace std;

long long exponential(int n, int k){
    long long res = 1;
    while(k){
        if( k&1 ) res *= n;
        n *= n;
        k/=2;
    }
    return res;
}

int main(){
   int n,k;
   cout<<"Enter the base and power "<<endl;
   cin>>n>>k;
   cout<<exponential(n,k)<<endl;
}