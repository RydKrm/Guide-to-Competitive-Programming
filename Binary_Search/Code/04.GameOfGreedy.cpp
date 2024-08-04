#include<iostream>
#include<vector>
using namespace std;

bool divideAmongK(vector<int> arr, int n, int k, int coins){
   int partions = 0, current_friend = 0;
   for(int i=0;i<n;i++){
    if(current_friend + arr[i] >= coins){
        partions++;
        current_friend = 0;
    } else {
        current_friend += arr[i];
    }
   }

   return partions >= k;
}

int main(){
    // number of coins and friends
    int n,k; cin>>n>>k;

    // coins list 
    vector<int> arr;
    for(int i=0;i<n;i++){
        int num; cin>>num;
        arr.push_back(num);
    }
    int start = 0, end = 0, ans = 0;
    for(int i=0;i<n;i++) {
        end += arr[i];
    }

    while(start < end){
        int mid = (start + end)/2;
        // cout<<mid<<endl;
        bool isPossible = divideAmongK(arr,n,k,mid);
        if(isPossible){
            start = mid + 1;
            ans = mid;
        } else {
            end =  mid - 1;
        }
    }

    cout<<ans<<endl;

    return 0;
}