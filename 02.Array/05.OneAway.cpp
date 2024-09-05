// One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.
// EXAMPLE
// pale, ple -> true 
// pales, pale -> true 
// pale, bale -> true
// pale, bake -> false

#include<iostream>
#include<string>
#include<map>
#include<stdio.h>
using namespace std;

bool OneAway(string str1, string str2){
    // if the length difference more than 1 then return false
    int dif = str1.size() - str2.size();
    if(abs(dif)>1){
        return false;
    }
    // if string has more than one difference return false
    if(str1.size() == str2.size()){
        int les = 0;
        for (int i = 0; i < str1.size();i++){
            if(str1[i] != str2[i])
                les++;
        }
        if(les>1)
            return false;   
    }

    // if the difference is one then small one be the subset of big one
    string mn, mx;
    if(str1.size() > str2.size()){
        mn = str2;
        mx = str1;
    } else {
        mx = str2;
        mn = str1;
    }

    map<char, int> checker;
    
    for(char m:mx)
        checker[m]++;

    for(char m:mn){
        if(!checker.count(m))
            return false;
    }
    // otherwise return true
    return true;
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    if(OneAway(str1, str2)){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}