/*********************************************************************************
 * Leetcode : Reverse Integer -- https://leetcode.com/problems/reverse-integer/
 * Coded in Seq 2nd, 2015
 *
 * [Problem]
 *  Reverse digits of an integer.
 * 
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 * 
 * Have you thought about this?
 * Here are some good questions to ask before coding. Bonus points for you
 * if you have already thought through this!
 * 
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 * 
 * Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer,
 * then the reverse of 1000000003 overflows. How should you handle such cases?
 * 
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 *********************************************************************************/
#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;

int reverse (int x) {
    long result = 0;
    while (x) {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return (result < INT_MIN || result > INT_MAX) ? 0 : result;
}

int main(int argc, const char *argv[]) {
    int __;
    while (cin >> __) {
        cout << reverse(__) << endl;
    } 
    return 0;
}
