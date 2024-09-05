// Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

// Input: Tact Coa
// Output: Tact Coa True (permutations: "taco cat", "atco eta", etc.)

#include<iostream>
#include<string>
#include<string.h>
#include<map>
using namespace std;

bool find_permutation(char str[], int len){
    map<char, int> mp;
    for (int i = 0; i < len;i++){
        mp[str[i]]++;
    }
    int cnt = 0;
    for(auto x:mp){
        if(x.second%2)
            cnt++;
    }
    if(cnt%2)
        return false;
    else
        return true;
}

int main(){
    string input;
    getline(cin, input); 

    int true_len = input.length(); 

    char str[100];
    strcpy(str, input.c_str());
    if(find_permutation(str,true_len)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}