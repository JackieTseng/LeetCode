/*********************************************************************************
 * Leetcode : Find the Duplicate Number -- https://leetcode.com/problems/find-the-duplicate-number/ 
 * Coded in Seq 1st, 2015
 *
 * [Problem]
 * Given an array nums containing n + 1 integers where each integer is between 1
 * and n (inclusive), prove that at least one duplicate number must exist. Assume
 * that there is only one duplicate number, find the duplicate one.
 * 
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once. 
 *********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int size = nums.size();
    int l = 1, h = size - 1, mid, counter;
    while (l < h) {
        mid = (l + h) / 2;
        counter = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] <= mid) {
                counter += 1;
            }
        }
        if (counter > mid) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
    
int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(2);
	cout << findDuplicate(nums) << endl;
	return 0;
}
