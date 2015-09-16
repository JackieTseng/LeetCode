/*********************************************************************************
 * Leetcode : Triangle -- https://leetcode.com/problems/triangle/ 
 * Coded in Seq 16th, 2015
 *
 * [Problem]
 * Given a triangle, find the minimum path sum from top to bottom. Each step you
 * may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * [
 *      [2],
 *     [3,4],
 *    [6,5,7],
 *   [4,1,8,3]
 * ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n is
 * the total number of rows in the triangle. 
 *********************************************************************************/
#include <iostream>
#include <limits.h>
#include <vector>
#include <cmath>
using namespace std;

// Solution One
int minimumTotal(vector<vector<int> >& triangle) {
    int r = triangle.size();
    vector<vector<int> > dp(triangle);
    for (int i = r - 2; i >= 0 ; i--) {
        int size = dp[i].size();
        for (int j = 0; j < size; j++) {
            dp[i][j] += min(dp[i + 1][j], dp[i + 1][j + 1]);
        } 
    }
    return dp[0][0];
}

int main(int argc, const char *argv[]) {
    vector<int> one;
    one.push_back(2);
    vector<int> two;
    two.push_back(3);
    two.push_back(4);
    vector<int> three;
    three.push_back(6);
    three.push_back(5);
    three.push_back(7);
    vector<int> four;
    four.push_back(4);
    four.push_back(1);
    four.push_back(8);
    four.push_back(3);
    vector<vector<int> > t;
    t.push_back(one);
    t.push_back(two);
    t.push_back(three);
    t.push_back(four);
    cout << minimumTotal(t) << endl;
    return 0;
}
