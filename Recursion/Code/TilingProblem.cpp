#include<iostream>
using namespace std;

int tiling(int n){
  if(n<4) return 1;
  else {
    return tiling(n-1) + tiling(n-4);
  }
}

int main(){
  int n;
  cin>>n;
  int ans = tiling(n);
  cout<<"Total number of ways "<<ans<<endl;
}
