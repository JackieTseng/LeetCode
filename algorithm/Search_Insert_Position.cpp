/*********************************************************************************
 * Leetcode : Search Insert Position -- https://leetcode.com/problems/search-insert-position/
 * Coded in Seq 1st, 2015
 *
 * [Problem]
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0 
 *********************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

// Solution One
int searchInsert(int A[], int n, int target) {
    for (int index = 0; index < n; index++) {
        if (target <= A[index]) {
            return index;
        }
        if (index == n - 1) {
            return index + 1;
        }
    }
}

// Solution Two
int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}


// Solution Three
int searchInsert(vector<int>& nums, int target) {
    return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int main(int argc, const char *argv[]) {
    while (true) {
        int n, target, t;
        vector<int> array;
        cin >> n;
        while (n--) {
            cin >> t;
            array.push_back(t);
        }
        cin >> target;
        cout << searchInsert(array, target) << endl; 
    }
    return 0;
}
