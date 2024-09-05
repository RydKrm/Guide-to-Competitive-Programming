// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

#include <stdio.h>
#include<iostream>
using namespace std;

bool hasUniqueCharacters(string str) {
    int charCount[256] = {0}; // Assuming ASCII characters

    for (int i = 0; str[i] != '\0'; i++) {
        int charIndex = str[i];

        if (charCount[charIndex] > 0) {
            return false; // Character already encountered
        }

        charCount[charIndex]++;
    }

    return true; // All characters encountered once
}

int main() {
    string str;
    cin >> str;
    if(hasUniqueCharacters(str)) {
        cout << "The string has all unique characters." << endl;
    } else {
        cout << "The string has duplicate characters." << endl;
    }
    return 0;
}