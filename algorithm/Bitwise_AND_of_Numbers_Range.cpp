/*********************************************************************************
 * Leetcode : Bitwise AND of Numbers Range -- https://leetcode.com/problems/bitwise-and-of-numbers-range/ 
 * Coded in Seq 3rd, 2015
 *
 * [Problem]
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of
 * all numbers in this range, inclusive.
 * 
 * For example, given the range [5, 7], you should return 4. 
 *********************************************************************************/
#include <iostream>
#include <limits.h>
using namespace std;

// Solution One
int rangeBitwiseAnd(int m, int n) {
    int mask = INT_MAX;
    while ((m & mask) != (n & mask)) {
        mask <<= 1;
    }
    return m & mask;
}

// Solution Two
int rangeBitwiseAnd(int m, int n) {
    int counter = 0;
    while (m != n) {
        m >>= 1;
        n >>= 1;
        ++i;
    }
    return m << i;
}

int main(int argc, const char *argv[]) {
    int m, n;
    while (cin >> m >> n) {
        cout << rangeBitwiseAnd(m, n) << endl;
    } 
    return 0;
}
