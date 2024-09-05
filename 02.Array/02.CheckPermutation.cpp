// * Given two strings, write a method to decide if one is a permutation of the other.
#include<iostream>
#include<unordered_map>
using namespace std;

bool check_permutation(string str1, string str2) {
    // If the lengths are different, they cannot be permutations
    if (str1.length() != str2.length()) {
        return false;
    }

    // Create a frequency map for characters in str1
    unordered_map<char, int> freq_map;

    for (char s : str1) {
        freq_map[s]++;
    }

    // Check if the same frequency is found in str2
    for (char s : str2) {
        if (freq_map.find(s) == freq_map.end() || freq_map[s] == 0) {
            return false;
        }
        freq_map[s]--;
    }

    return true;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    if (check_permutation(str1, str2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
