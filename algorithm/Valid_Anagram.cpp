/*********************************************************************************
 * Leetcode : Valid Anagram -- https://leetcode.com/problems/valid-anagram/
 * Coded in Aug 12th, 2015
 *
 * [Problem]
 * Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *********************************************************************************/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// Solution One
bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (t == s) {
        return true;
    } else {
        return false;
    }
}
 
// Solution Two
bool isAnagram(string s, string t) {
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    int flag[26] = {0};
    int length = s.length();
    for (int i = 0; i < length; i++) {
        ++flag[s[i] - 97];
        --flag[t[i] - 97];
    }
    for (int i = 0; i < 26; i++) {
        if (flag[i] != 0) {
            return false; 
        }
    }
    return true;
}

int main(int argc, const char *argv[]) {
    cout << (isAnagram("nl", "cx")?"Y":"N") << endl;
    return 0;
}
