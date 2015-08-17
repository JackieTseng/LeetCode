/*********************************************************************************
 * Leetcode : Power of Two -- https://leetcode.com/problems/power-of-two/
 * Coded in Aug 17th, 2015
 *
 * [Problem]
 * Given an integer, write a function to determine if it is a power of two.
 *********************************************************************************/
#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return (n > 0 && (n & (n - 1)) == 0);
}

int main(int argc, const char *argv[]) {
    int number;
    while (cin >> number) {
        cout << (isPowerOfTwo(number)?"yes":"no") << endl; 
    }
    return 0;
}
