/*********************************************************************************
 * Leetcode : Rotate Array -- https://leetcode.com/problems/rotate-array/ 
 * Coded in Oct 21st, 2015
 *
 * [Problem]
 * Rotate an array of n elements to the right by k steps.
 * 
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 * 
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 * 
 * [show hint]
 * 
 * Hint:
 * Could you do it in-place with O(1) extra space? 
 *********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

// Solution One
void rotate(vector<int>& nums, int k) {
	int n = nums.size();
	vector<int> temp(n, 0);
	k %= n;
	for (int i = 0; i < n; i++) {
		temp[(i + k) % n] = nums[i];
	}
	nums = temp;
}

int main(int argc, const char *argv[]) {
	vector<int> number;
	for (int i = 1; i < 8; i++) {
		number.push_back(i);
	}
	rotate(number, 3);
	for (int i = 0; i < number.size(); i++) {
		cout << number[i] << " ";
	}
	return 0;	
}
