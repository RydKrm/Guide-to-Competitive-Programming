// Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

string compression(string str){
    unordered_map<char,int> checker;
    for(char s:str){
        checker[s]++;
    }
    string ans = "";
    for(auto m:checker){
        ans += m.first;
        ans += to_string(m.second);
    }
    return ans;
}

int main(){
    string str;
    cin >> str;
    string ans = compression(str);
    if(ans.size() > str.size()){
        cout << str << endl;
    } else {
        cout << ans << endl;
    }
}