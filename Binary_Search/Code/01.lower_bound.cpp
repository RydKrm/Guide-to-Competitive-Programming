#include<iostream>
#include<vector>
using namespace std; 

int lower_bound(vector<int> arr, int key){
   int start = 0, end = arr.size() - 1;
   int ans = -1;

   while(start < end){
     int mid = (start + end) / 2;
     if (arr[mid] == key){
        ans = arr[mid];
        end = mid - 1;
     } else if(arr[mid] > key) {
        end = mid - 1;
     } else {
        start = mid + 1;
     }
   }
   return ans;
}

int main(){
  vector<int> arr = {0,1,1,2,2,3,3,3,3,4,5,5,5,10};
  int n = arr.size(), key = 3;
  cout<< lower_bound(arr, key) <<endl;
  return 0;
}