/*********************************************************************************
 * Leetcode : Move Zeroes -- https://leetcode.com/problems/move-zeroes/ 
 * Coded in Seq 23rd, 2015
 *
 * [Problem]
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums
 * should be [1, 3, 12, 0, 0].
 * 
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations. 
 *********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

 void moveZeroes(vector<int>& nums) {
    vector<int> result;
    int size = nums.size(), counter = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] != 0) {
            result.push_back(nums[i]);
        } else {
            counter++;
        }
    }
    for (int i = 0; i < counter; i++) { 
        result.push_back(0);
    }
    nums = result;
}

int main(int argc, const char *argv[]) {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(12);
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
