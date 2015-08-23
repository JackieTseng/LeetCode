/*********************************************************************************
 * Leetcode : Excel Sheet Column Number -- https://leetcode.com/problems/excel-sheet-column-number/
 * Coded in Aug 23th, 2015
 *
 * [Problem]
 * Related to question Excel Sheet Column Title
 * 
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 * 
 * For example:
 * 
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28 
 *********************************************************************************/
#include <iostream>
using namespace std;

int titleToNumber(string s) {
    int result = 0, length = s.length();
    for (int i = 0; i < length; i++) {
        result = result * 26 + ((int)s[i] - 64);
    }
    return result ;
}

int main(int argc, const char *argv[]) {
    string in;
    while (cin >> in) {
        cout << titleToNumber(in) << endl; 
    }
    return 0;
}
