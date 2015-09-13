#include <iostream>
using namespace std;

// Solution One
int dp[1000] = {0};

int climbStairs(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return n;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    dp[1] = 1;
    dp[2] = 2;
    dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    return dp[n];
}

// Solution Two
int climbStairs(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return n;
    }
    int* dp = new int[n];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; 
    }
    return dp[n - 1];
}

int main(int argc, const char *argv[]) {
    int t;
    while (cin >> t) {
        cout << climbStairs(t) << endl;
    }
    return 0;
}
