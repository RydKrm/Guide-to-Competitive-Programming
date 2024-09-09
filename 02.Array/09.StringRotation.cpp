// Assumeyou have a method isSubstringwhich checks if oneword is a substring of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one call to isSubstring
// Input :- waterbottle
// Output :- erbottlewat

#include<iostream>
#include<vector>
using namespace std;

// * Logic
// second string is rotated with n time. if two rotated string can be concat then it could be a full stirng  for example.
// s1 =  table s2 = bleta
// con = s2 + s2; ble'table'ta
// then their could be a stirng of string s1. Just need to check after concat the concat string could
// be contain s2 as a string or not
bool isRotation(string str1, string str2){
    string con = str2 + str2;
    if(con.find(str1) != string::npos){
        return true;
    } else {
        return false;
    }
    
}
int main(){
    string str1, str2;
    cin>>str1>>str2;
    if(isRotation(str1, str2)){
        cout<<"True"<<endl;
    } else {
        cout<<"False"<<endl;
    }
}