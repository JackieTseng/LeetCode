/*********************************************************************************
 * Leetcode : Count and Say -- https://leetcode.com/problems/count-and-say/ 
 * Coded in Oct 24th, 2015
 *
 * [Problem]
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string. 
 *********************************************************************************/
#include <iostream>
using namespace std;

string countAndSay(int n) {
    string s = "1";
    while (--n) {
        string t = "";
        int l = s.length();
        for (int i = 0; i < l; i++) {
            char c = s[i];
            int counter = 1;
            for (int j = i + 1; j < l; j++) {
                if (s[j] != c) {
                    break;
                }
                counter++;
                i = j;
            }
            t += (counter + '0');
            t += c;
        }
        s = t;
    }
    return s;
}

int main(int argc, const char *argv[]) {
    int n;
    while (cin >> n) {
        cout << countAndSay(n) << endl;
    }
    return 0;
}
