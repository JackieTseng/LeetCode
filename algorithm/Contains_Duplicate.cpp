/*********************************************************************************
 * Leetcode : Contains Duplicate -- https://leetcode.com/problems/contains-duplicate/
 * Coded in Seq 6th, 2015
 *
 * [Problem]
 * Given an array of integers, find if the array contains any duplicates. Your function
 * should return true if any value appears at least twice in the array, and it should
 * return false if every element is distinct.
 *********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Solution One
bool containsDuplicate(vector<int>& nums) {
    map<int, bool> hTable;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (hTable.find(nums[i]) == hTable.end()) {
            hTable[nums[i]] = true;
        } else {
            return true;
        }
    } 
    return false;
}

int main(int argc, const char *argv[]) {
    vector<int> test;
    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        test.push_back(t);
    }
    cout << (containsDuplicate(test) ? "Yes" : "No") << endl;
    return 0;
}
