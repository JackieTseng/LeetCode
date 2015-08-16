/*********************************************************************************
 * Leetcode : Add Digits -- https://leetcode.com/problems/add-digits/
 * Coded in Aug 16th, 2015
 *
 * [Problem]
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 *
 * For example:
 * 
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 * Hint:
 * 
 * 1. A naive implementation of the above process is trivial. Could you come up with other methods?
 * 2. What are all the possible results?
 * 3. How do they occur, periodically or randomly?
 *********************************************************************************/
#include <iostream>
#include <iostream>
using namespace std;

// Solution One
int addDigits(int num) {
    while (num / 10 != 0) {
        int temp = 0;
        while (num != 0) {
            temp += num % 10;
            num /= 10;
        }
        num = temp; 
    }
    return num;
}

// Solution Two
int addDigits(int num) {
    return (num - 1) % 9 + 1;   
}

int main(int argc, const char *argv[]) {
    for (int i = 1; i < 21; i++) {
        cout << i << " " << addDigits(i) << endl;
    }
    return 0;
}
