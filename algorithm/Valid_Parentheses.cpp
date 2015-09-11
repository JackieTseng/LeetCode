/*********************************************************************************
 * Leetcode : Valid Parentheses -- https://leetcode.com/problems/valid-parentheses/
 * Coded in Seq 12th, 2015
 *
 * [Problem]
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid
 * but "(]" and "([)]" are not. 
 *********************************************************************************/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> r;
    int l = s.length();
    for (int i = 0; i < l; i++) {
        if (!r.empty()) {
            char c = r.top();  
            if ((c == '(' && s[i] == ')') ||
                (c == ')' && s[i] == '(') ||
                (c == '[' && s[i] == ']') ||
                (c == ']' && s[i] == '[') ||
                (c == '{' && s[i] == '}') ||
                (c == '}' && s[i] == '{')) {
                r.pop();
                continue;
            }
        }
        r.push(s[i]);
    }
    return r.empty();
}

int main(int argc, const char *argv[]) {
    string t;
    while (cin >> t) {
        cout << (isValid(t) ? "Yes" : "No") << endl;    
    }
    return 0;
}
