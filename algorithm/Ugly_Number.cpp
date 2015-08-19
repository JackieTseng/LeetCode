/*********************************************************************************
 * Leetcode : Ugly Number -- https://leetcode.com/problems/ugly-number/ 
 * Coded in Aug 19th, 2015
 *
 * [Problem]
 * Write a program to check whether a given number is an ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 * 
 * Note that 1 is typically treated as an ugly number.
 *********************************************************************************/
#include <iostream>
using namespace std;

bool isUgly(int num) {
    if (num <= 0) {
        return false;
    } else {
        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2; 
            } else if (num % 3 == 0) {
                num /= 3;
            } else if (num % 5 == 0) {
                num /= 5;
            } else {
                return false;
            }
        }
        return true;
    }
}

bool isUgly(int num) {
    if (num < 1) {
        return false;
    }
    for (int i = 2; i <= 5; i++) {
        while (num % i == 0) {
            num /= i;
        }
    }
    return 1 == num;
}

int main(int argc, const char *argv[]) {
    int n;
    while (cin >> n) {
        cout << (isUgly(n)? "Yes" : "No") << endl;
    }
    return 0;
}
