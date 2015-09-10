/*********************************************************************************
 * Leetcode : Perfect Squares -- https://leetcode.com/problems/perfect-squares/
 * Coded in Seq 10th, 2015
 *
 * [Problem]
 * Given a positive integer n, find the least number of perfect square numbers 
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
 * return 2 because 13 = 4 + 9. 
 *********************************************************************************/
#include <iostream>
#include <limits.h>
#include <vector>
#include <cmath>
using namespace std;

// Solution One
int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; i + j * j <= n; j++) {
            dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
        }
    }
    return dp[n];
}

int main(int argc, const char *argv[]) {
    int t;
    while (cin >> t) {
        cout << numSquares(t) << endl;
    }
    return 0;
}
