/*********************************************************************************
 * Leetcode : Valid Number -- https://leetcode.com/problems/valid-number/
 * Coded in Seq 1st, 2015
 *
 * [Problem]
 * Validate if a given string is numeric.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 *
 * Note: It is intended for the problem statement to be ambiguous. You should gather
 * all requirements up front before implementing one.
 *********************************************************************************/
#include <iostream>
#include <string>
using namespace std;

bool isNumber(string s) {
    int i = 0, length = s.length();
    while (s[i] == ' ') {
        ++i;
    }
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }
    int num, point;
    for (num = 0, point = 0; i < length && (isdigit(s[i]) || s[i] == '.'); ++i) {
        s[i] == '.' ? ++point : ++num; 
    }
    if (point > 1 || num < 1) {
        return false;
    }
    if (s[i] == 'e') {
        ++i;
        if (s[i] == '+' || s[i] == '-') {
            ++i;
        }
        for (num = 0; i < length && isdigit(s[i]) ; ++i, ++num) {
        }
        if (num < 1) {
            return false;
        }
    }
    while (s[i] == ' ') {
        ++i;
    }
    return i == length;
}

int main(int argc, const char *argv[]) {
    string t;
    while (cin >> t) {
        cout << (isNumber(t) ? "Yes" : "No") << endl;
    } 
    return 0;
}
