#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    string num1, num2;
    cin>>num1>>num2;

    // reverse the to  string so that after adding if it contains carry bit, it can be added to the end of the result string
    
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    // the length of the two string can be different so smallest one need to place at the end so that , i can loop though to that position and 
    //other position can be added in the end 

    if (num1.length() < num2.length()){
        swap(num1, num2);
    }

    // cout<< "num1 "<<num1<< "\nnum2 "<<num2<<endl;

    // Now start the iteration from the begin. Added two number if it greater than 9 a carry left 
    int carry = 0;
    string ans = "";
    for(int i = 0; i < num2.length(); i++){
        int first = num1[i] - '0';
        int second = num2[i] - '0';
        char less = ((first + second + carry)%10) + '0';
        ans += less;
        carry = (first + second + carry)/10;
    }

    // Now if num1 is greater than num2 then, added the extra number to the answer 

    for(int i = num2.length(); i < num1.length(); i++){
        int num = num1[i] - '0';
        char less = ((carry + num) % 10) + '0';
        ans += less;
        carry = (num + carry) / 10;
    }

    // if again left a carry 
    if(carry) ans += (carry + '0');
    
    reverse(ans.begin(),ans.end());

    cout<<ans<<endl;

    return 0;
}