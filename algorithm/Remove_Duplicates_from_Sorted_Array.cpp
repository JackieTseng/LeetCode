/*********************************************************************************
 * Leetcode : Remove Duplicates from Sorted Array -- https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Coded in Oct 16th, 2015
 *
 * [Problem]
 * Given a sorted array, remove the duplicates in place such that each element appear
 * only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this in place with
 * constant memory.
 * 
 * For example,
 * Given input array nums = [1,1,2],
 * 
 * Your function should return length = 2, with the first two elements of nums being
 * 1 and 2 respectively. It doesn't matter what you leave beyond the new length. 
 *********************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution One
int removeDuplicates(vector<int>& nums) {
	int length = nums.size();
	if (length < 2) {
		return length;
	}
	int iter = 1;
	for (int i = 1; i < length; i++) {
		if (nums[i] != nums[i - 1]) {
			nums[iter++] = nums[i];
		}
	}
	//nums.erase(nums.begin() + iter, nums.end());
	return iter;
}

// Solution Two
int removeDuplicates(vector<int>& nums) {
	return unique(nums.begin(), nums.end()) - nums.begin();
}

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	cout << removeDuplicates(nums) << endl;
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	return 0;
} 
