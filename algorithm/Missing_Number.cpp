/*********************************************************************************
 * Leetcode : Missing Number -- https://leetcode.com/problems/missing-number/ 
 * Coded in Seq 5th, 2015
 *
 * [Problem]
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * For example,
 * Given nums = [0, 1, 3] return 2.
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity? 
 *********************************************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Solution One
int missingNumber(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size; i++) {
        if (!i && nums[i]) {
            return 0;
        }
        if (nums[i + 1] != nums[i] + 1) {
            return nums[i] + 1;
        }
    }
}

// Solution Two
int missingNumber(vector<int>& nums) {
    int size = nums.size();
    int r = 0;
    for (int i = 0; i < size; i++) {
        r ^= i ^ nums[i]; 
    }
    return r ^ size;
}

int main(int argc, const char *argv[]) {
    vector<int> test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(3);
    cout << missingNumber(test) << endl;
    return 0;
}
