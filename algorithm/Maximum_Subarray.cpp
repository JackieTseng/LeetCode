/*********************************************************************************
 * Leetcode : Maximum Subarray -- https://leetcode.com/problems/maximum-subarray/
 * Coded in Seq 14th, 2015
 *
 * [Problem]
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest sum.
 * 
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 * 
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the
 * divide and conquer approach, which is more subtle. 
 *********************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Solution One
// Dynamic Programming
int maxSubArray(vector<int>& nums) {
    int size = nums.size(), ans = nums[0];
    for (int i = 0, sum = 0; i < size; i++) {
        sum += nums[i];
        ans = max(sum, ans);
        sum = max(sum, 0);
    }
    return ans;
}

// Solution Two
// Dynamic Programming
int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    int* dp = new int[size];
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 1; i < size; i++) {
        dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Solution Three
// Divide and Conquer
int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    return (!size ? 0 : maxSubArrayHelper(nums, 0, size - 1));
}

int maxSubArrayHelper(vector<int>& nums, int l, int r) {
    if (l == r) {
        return nums[l];
    }
    int m = (l + r) / 2;
    int left_max = maxSubArrayHelper(A, l, m);
    int right_max = maxSubArrayHelper(A, m + 1, r);
    int mid_to_left_max = nums[m];
    int mid_to_right_max = nums[m + 1];
    for (int i = m, temp = 0; i >= l; i--) {
        temp += nums[i];
        mid_to_left_max = max(mid_to_left_max, temp);
    }
    for (int i = m + 1, temp = 0; i <= r; i++) {
        temp += nums[i];
        mid_to_right_max = max(mid_to_right_max, temp);
    }
    return max(max(left_max, right_max), mid_to_left_max + mid_to_right_max);
}

int main(int argc, const char *argv[]) {
    int t[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; 
    vector<int> temp = vector<int>(t, t + (sizeof(t) / sizeof(int)));
    cout << maxSubArray(temp) << endl;
    return 0;
}
