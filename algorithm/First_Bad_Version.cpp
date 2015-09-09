/*********************************************************************************
 * Leetcode :First Bad Version -- https://leetcode.com/problems/first-bad-version/ 
 * Coded in Seq 9th, 2015
 *
 * [Problem]
 * You are a product manager and currently leading a team to develop a new product.
 * Unfortunately, the latest version of your product fails the quality check. Since
 * each version is developed based on the previous version, all the versions after
 * a bad version are also bad.
 * 
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad
 * one, which causes all the following ones to be bad.
 * 
 * You are given an API bool isBadVersion(version) which will return whether version
 * is bad. Implement a function to find the first bad version. You should minimize the
 * number of calls to the API. 
 *********************************************************************************/
#include <iostream>
using namespace std;

bool isBadVersion(int version) {
    return version > 5;
}

int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (isBadVersion(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return r;
}

int main(int argc, const char *argv[]) {
    int t;
    while (cin >> t) {
        cout << firstBadVersion(t) << endl;
    }
    return 0;
}
