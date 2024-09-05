#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

vector<char> convert_string(char str[], int len) {
    vector<char> ans;
    while(str[len-1] ==' '){
        len--;
    }
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            ans.push_back('%');
            ans.push_back('2');
            ans.push_back('0');
        } else {
            ans.push_back(str[i]);
        }
    }
    return ans;
}

int main() {
    string input;
    getline(cin, input); 

    int true_len = input.length(); 

    char str[100];
    strcpy(str, input.c_str());

    vector<char> ans = convert_string(str, true_len);

    for (char a : ans)
        cout << a;

    return 0;
}
