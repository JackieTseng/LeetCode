/*********************************************************************************
 * Leetcode : Length of Last Word -- https://leetcode.com/problems/length-of-last-word/
 * Coded in Aug 13th, 2015
 *
 * [Problem]
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 *********************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int len = 0, ptr = 0;
    int length = s.length();
    while (ptr != length) {
        if (s[ptr++] != ' ') {
            ++len;
        } else if (s[ptr] && s[ptr] != ' '){
            len = 0;
        }
    }
    return len;
}

int main(int argc, const char *argv[]) {
    cout << lengthOfLastWord("ab cdef") ;
    return 0;
}
