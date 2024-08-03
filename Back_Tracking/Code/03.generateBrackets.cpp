#include <iostream>
#include <vector> 
using namespace std;

void generateBracket(int n, int opening, int closing, vector<char> curr, vector<vector<char>> &result){

    if(opening == n && closing == n) {
        result.push_back(curr);
        return;
    }

    if(opening < n){
        curr.push_back('(');
        generateBracket(n, opening + 1, closing, curr, result);
        curr.pop_back();
    }

    if(closing < opening){
        curr.push_back(')');
        generateBracket(n, opening, closing + 1, curr, result);
    }
}

int main(){
   int n;
   cin>>n;

   vector<vector<char>> result;
   vector<char> curr; 
   int opening = 0, closing = 0;
   generateBracket(n, opening, closing, curr, result);

   for(vector<char> res : result) {
     for(char c:res){
        printf("%c", c);
     }
     cout<<endl;
   }
   return 0;
}