/*********************************************************************************
 * Leetcode : Reverse Words in a String -- https://leetcode.com/problems/reverse-words-in-a-string/  
 * Coded in Seq 1st, 2015
 *
 * [Problem]
 * Given an input string, reverse the string word by word.
 * 
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *********************************************************************************/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

// Solution One
void reverseWords(string &s) {
    stack<string> temp;
    string word, newString;
    int length = s.size();
    for (int i = 0; i < length; i++) {
        if (s[i] != ' ') {
            word.push_back(s[i]);
            if (i + 1 == length || s[i + 1] == ' ') {
                word += " ";
                temp.push(word);
                word.clear();
            }
        }
    }
    while (!temp.empty()) {
        newString += temp.top();
        temp.pop();
    }
    if (newString.size() != 0) {
        newString.erase(newString.end() - 1);
        s = newString;
    } else {
        s.clear();
    }
}

// Solution Two
void reverseWords(string &s) {
    string newString;
    int index = 0, length = s.length();
    for (int i = 0; i < length; ++i) {
        if (s[i] == ' ') {
            if (i > index) {
                newString = s.substr(index, i - index) + " " + newString;
            }
            index = i + 1;
        } else if (i == length - 1) {
            newString = s.substr(index, length - index) + " " + newString;
        }
    }
    s = newString.substr(0, newString.size() - 1);
}

int main(int argc, const char *argv[]) {
    char x[100];
    while (fgets(x, 100, stdin)) {
        x[strlen(x) - 1] = '\0';
        string t = x;
        reverseWords(t);
        cout << t << endl;
    } 
    return 0;
}
