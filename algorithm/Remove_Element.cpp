/*********************************************************************************
 * Leetcode : Remove Element -- https://leetcode.com/problems/remove-element/
 * Coded in Seq 12th, 2015
 *
 * [Problem]
 * Given an array and a value, remove all instances of that value in place and
 * return the new length.
 * 
 * The order of elements can be changed. It doesn't matter what you leave beyond
 * the new length.
 *********************************************************************************/
#include <iostream>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int newLength = 0, size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] != val) {
            nums[newLength++] = nums[i];
        }
    }
    return newLength;
}

int main(int argc, const char *argv[]) {
    return 0;
}
