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
#include <set>
using namespace std;

// Solution One
/*
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
*/

// Solution Two
/*
int numSquares(int n) {
    static vector<int> dp{0};
    int m = dp.size();
    if (m > n) {
        return dp[n];
    }
    dp.resize(max(m, n + 1), INT_MAX);
    for (int i = 0; i <= n; i++) {
        for (int j = 1; i + j * j <= n; j++) {
            dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
        }
    }
    return dp[n];
}
*/

// Solution Three
int numSquares(int n) {
    set<int> x1, x2;
    int i = 1;
    while (i * i <= n) {
        x1.insert(i * i);
        i++;
    }
    if (x1.find(n) != x1.end()) {
        return 1;
    }
    set<int>::iterator p1, p2;
    for (p1 = x1.begin(); p1 != x1.end(); p1++) {
        for (p2 = x1.begin(); p2 != x1.end(); p2++) {
            x2.insert((*p1) + (*p2));
        }
    }
    if (x2.find(n) != x2.end()) {
        return 2;
    }
    for (p1 = x1.begin(); p1 != x1.end(); p1++) {
        if (x2.find(n - (*p1)) != x2.end()) {
            return 3;
        }
    }
    return 4;
}

int main(int argc, const char *argv[]) {
    int t;
    while (cin >> t) {
        cout << numSquares(t) << endl;
    }
    return 0;
}
