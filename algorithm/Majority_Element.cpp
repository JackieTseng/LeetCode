/*********************************************************************************
 * Leetcode : Majority Element -- https://leetcode.com/problems/majority-element/
 * Coded in Aug 12th, 2015
 *
 * [Problem]
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.

 * You may assume that the array is non-empty and the majority element always 
 * exist in the array.
 *********************************************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int cur, counter = 0;
    int length = nums.size();
    for (int i = 0; i < length; ++i) {
        if (counter == 0) {
            cur = nums[i];
            ++counter;
        } else {
            if (nums[i] == cur) {
                ++counter;
            } else {
                --counter;
            }
        }
    }
    return cur;
}

int main(int argc, const char *argv[]) {
    int t[] = {6, 4, 3, 5, 5, 1};
    vector<int> v;
    for (int i = 0; i < 6; i++) {
       v.push_back(t[i]); 
    }
    cout << majorityElement(v) << endl;
    return 0;
}
