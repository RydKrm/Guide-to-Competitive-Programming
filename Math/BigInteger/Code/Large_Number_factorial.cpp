#include<iostream>
#include<vector>
using namespace std;

void multiply(vector<int> &ans,int num, int &size){
    int carry = 0;
    for(int i=0; i<size; i++){
        int product = ans[i] * num + carry;
        ans[i] = product % 10;
        carry = product / 10;
    }

    // handle the carry 
    while(carry){
        ans[size] = carry % 10;
        carry = carry/10;
        size++;
    }

}

int main(){
    int n;
    cin>>n;

    vector<int> ans(1000,0);
    ans[0] = 1;
    int size = 1;

    for(int i=2;i<=n;i++){
        multiply(ans, i, size);
    }

    for(int i = size - 1; i>=0; i--){
        cout<<ans[i];
    }

    return 0;
}  