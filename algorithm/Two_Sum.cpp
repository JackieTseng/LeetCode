/*********************************************************************************
 * Leetcode : Two Sum -- https://leetcode.com/problems/two-sum/ 
 * Coded in Seq 7th, 2015
 *
 * [Problem]
 * Given an array of integers, find two numbers such that they add up to a specific
 * target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add
 * up to the target, where index1 must be less than index2. Please note that your
 * returned answers (both index1 and index2) are not zero-based.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2 
 *********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int array[65000] = {0}, index[65000] = {0}, size = nums.size();
    for (int i = 0, temp = 0; i < size; i++) {
		temp = nums[i] + 32500;
        array[temp] = 1; 
        index[temp] = i + 1;
    }
    target += 32500;
    for (int i = 0; i < size; i++) {
        if (array[target - nums[i]] == 1 && index[target - nums[i]] != i + 1) {
			vector<int> result;
            result.push_back(i + 1);
            result.push_back(index[target - nums[i]]);
			return result;
        }
    }
}

int main(int argc, const char *argv[]) {
    vector<int> test;
    test.push_back(2); 
    test.push_back(7); 
    test.push_back(11); 
    test.push_back(15);
    vector<int> result = twoSum(test, 9);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
