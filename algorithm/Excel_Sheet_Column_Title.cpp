/*********************************************************************************
 * Leetcode : Excel Sheet Column Title -- https://leetcode.com/problems/excel-sheet-column-title/
 * Coded in Aug 19th, 2015
 *
 * [Problem]
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * 
 * For example:
 * 
 *  1 -> A
 *  2 -> B
 *  3 -> C
 *  ...
 *  26 -> Z
 *  27 -> AA
 *  28 -> AB 
 *********************************************************************************/
#include <iostream>
using namespace std;

string convertToTitle(int n) {
    return !n? "" : convertToTitle(n / 26) + (char)(--n % 26 + 'A');
}

int main(int argc, const char *argv[]) {
    int n;
    while (cin >> n) {
        cout << convertToTitle(n) << endl;
    }
    return 0;
}
