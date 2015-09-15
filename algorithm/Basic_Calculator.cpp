/*********************************************************************************
 * Leetcode : Basic Calculator -- https://leetcode.com/problems/basic-calculator/ 
 * Coded in Seq 15th, 2015
 *
 * [Problem]
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), the plus +
 * or minus sign -, non-negative integers and empty spaces .
 * 
 * You may assume that the given expression is always valid.
 * 
 * Some examples:
 * "1 + 1" = 2
 * " 2-1 + 2 " = 3
 * "(1+(4+5+2)-3)+(6+8)" = 23
 * Note: Do not use the eval built-in library function. 
 *********************************************************************************/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Solution One
int calculate(string s) {
    stack<int> sign;
    sign.push(1); // push + sign
    int result = 0, curNumber = 0, lastSign = 1, length = s.length();
    for (int i = 0; i < length; i++) {
        if (s[i] == '(') {
            sign.push(lastSign);
        } else if (s[i] == ')') {
            sign.pop();
        } else if (s[i] >= '0' && s[i] <= '9') {
            curNumber = 10 * curNumber + s[i] - '0';
        } else if (s[i] == '+' || s[i] == '-') {
            result += lastSign * curNumber;
            curNumber = 0;
            lastSign = (s[i] == '+' ? 1 : -1) * sign.top();
        }
    }
    result += lastSign * curNumber;
    return result;
}

// Solution Two
int calculate(string s) {
    stack<int> nums, signs;
    int curResult = 0, curNumber = 0, curSign = 1, length = s.length();
    for (int i = 0; i < length; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            curNumber = 10 * curNumber + s[i] - '0';
        } else {
            result += curSign * curNumber;
            curNumber = 0;
            if (s[i] == '+') {
                curSign = 1;
            } else if (s[i] == '-') {
                curSign = -1;
            } else if (s[i] == '(') {
                nums.push(curResult);
                signs.push(curSign);
                curResult = 0;
                curSign = 1;
            } else if (s[i] == ')') {
                curResult = signs.top() * curResult + nums.top();
                nums.pop();
                signs.pop();
            }
        }
    }
    curResult += curSign * curNumber;
    return curResult;
}

int main(int argc, const char *argv[]) {
    string t;
    while (getline(cin, t)) {
        cout << calculate(t) << endl;
    }   
    return 0;
}
