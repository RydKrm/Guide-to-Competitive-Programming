#include<iostream>
#include<stdio.h>
using namespace std;
/// 1,2,3,4,5,
void increasing(int n){
   if(n==0) return;
   increasing(n-1);
   printf("%d ",n);
}

void decreasing(int n) {
    printf("%d ",n);
   if(n==1) return;
   decreasing(n-1);
}

int main(){
    int n = 6;
  cout<<"Increasing order "<<endl;
 increasing(n);
 cout<<endl;

  cout<<"Decreasing order "<<endl;
 decreasing(n);
   return 0;
}
