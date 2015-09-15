/*********************************************************************************
 * Leetcode : Basic Calculator II -- https://leetcode.com/problems/basic-calculator-ii/
 * Coded in Seq 15th, 2015
 *
 * [Problem]
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, / operators
 * and empty spaces . The integer division should truncate toward zero.
 * 
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
 *
 * Note: Do not use the eval built-in library function.
 *********************************************************************************/
#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// Solution Two
// Reverse Polish Notation Method
int calculate(string s) {
    map<char, int> kv;
    kv['*'] = 2;
    kv['/'] = 2;
    kv['+'] = 1;
    kv['-'] = 1;
    kv['#'] = 0;
    stack<char> opts;
    vector<string> nums;
    opts.push('#');
    int length = s.length();
    string curNumber = "";
    for (int i = 0; i < length; i++) {
        if (s[i] == ' ') {
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            curNumber += s[i];
            if (i + 1 == length || !isdigit(s[i + 1])) {
                nums.push_back(curNumber);
                curNumber = "";
            }
        } else {
            if (s[i] == '(') {
                opts.push(s[i]);
            } else if (s[i] == ')') {
                while (opts.top() != '(') {
                    nums.push_back(string("") + opts.top());
                    opts.pop();
                }
                opts.pop();
            } else {
                if (opts.top() == '(') {
                    opts.push(s[i]);
                } else {
                    if (kv[s[i]] <= kv[opts.top()]) {
                        while (!(kv[s[i]] > kv[opts.top()] || opts.top() == '(')) {
                            nums.push_back(string("") + opts.top());
                            opts.pop();
                        }
                    }
                    opts.push(s[i]);
                }
            }
        }
    }
    while (!opts.empty()) {
        if (opts.top() != '#') {
            nums.push_back(string("") + opts.top());
        }
        opts.pop();
    }
    int sum = 0, size = nums.size();
    stack<int> numbers;
    for (int i = 0, num1 = -1, num2 = -1; i < size; i++) {
        if (nums[i].length() > 1) {
            numbers.push(atoi(nums[i].c_str()));
        } else {
            char c = nums[i][0];
            if (c >= '0' && c <= '9') {
                numbers.push(atoi(nums[i].c_str()));
            } else {
                num1 = numbers.top();
                numbers.pop();
                num2 = numbers.top();
                numbers.pop();
                if (c == '+') {
                    sum = (num2 + num1);     
                } else if (c == '-') {
                    sum = (num2 - num1);
                } else if (c == '*') {
                    sum = (num2 * num1);
                } else if (c == '/') {
                    sum = (num2 / num1);
                }
                numbers.push(sum);
            }
        }
    }
    return numbers.top();
}

int main(int argc, const char *argv[]) {
    string t;
    while (getline(cin, t)) {
        cout << calculate(t) << endl;
    }   
    return 0;
}
