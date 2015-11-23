/*********************************************************************************
 * Leetcode : Range Sum Query - Immutable -- https://leetcode.com/problems/range-sum-query-immutable/ 
 * Coded in Nov 23rd, 2015
 *
 * [Problem]
 * Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 * 
 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 *
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function. 
 *********************************************************************************/
#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> range;
    NumArray(vector<int> &nums) {
        int l = nums.size();
        range.push_back(0);
        for (int i = 0; i < l; i++) {
            range.push_back(range[i] + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return range[j + 1] - range[i];
    }
};

int main(int argc, const char *argv[]) {
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(-5);
    nums.push_back(2);
    nums.push_back(-1);
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
    return 0;
}
