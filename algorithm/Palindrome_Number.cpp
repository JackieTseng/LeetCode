/*********************************************************************************
 * Leetcode : Palindrome Number -- https://leetcode.com/problems/palindrome-number/
 * Coded in Seq 2nd, 2015
 *
 * [Problem]
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
 * you know that the reversed integer might overflow. How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 *********************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Solution One
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    // Reverse Integer
    int r = 0, num = x;
    while (num) {
        r = r * 10 + num % 10;
        num /= 10;
    }
    while (x) {
        if (x % 10 != r % 10) {
            return false;
        }
        x /= 10;
        r /= 10;
    }
    return true;
}

// Solution Two
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int num = x, counter = 0;
    while (num && ++counter) {
        num /= 10;
    }
    int number[32], count = 0;
    for (int i = 0; i < counter; i++) {
        if (i < counter / 2) {
            number[count++] = x % 10;
        } else {
            if (i == counter / 2 && (counter & 1) != 0) {
                x /= 10;
            }
            if (x % 10 != number[--count]) {
                return false;
            }
        }
        x /= 10;
        if (!x) {
            return true;
        }
    }
    return true;
}

// Solution Three
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    stringstream ss;
    ss << x;
    string s = ss.str();
    int length = s.length();
    for (int i = 0; i < length / 2; i++) {
        if (s[i] != s[length - i - 1]) {
            return false;
        } 
    }
    return true;
}

int main(int argc, const char *argv[]) {
    int __;
    while (cin >> __) {
        cout << (isPalindrome(__) ? "Yes" : "No") << endl;
    } 
    return 0;
}
