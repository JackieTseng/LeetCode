/*********************************************************************************
 * Leetcode : Summary Ranges -- https://leetcode.com/problems/summary-ranges/
 * Coded in Aug 26th, 2015
 *
 * [Problem]
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * 
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 *********************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    int length = nums.size();
    vector<string> result;
    if (!length) {
        return result;    
    }
    for (int i = 0; i < length; ++i) {
        int cur = nums[i];
        while (i + 1  < length && nums[i + 1] == nums[i] + 1) {
            ++i;
            continue;
        }
        if (nums[i] == cur) {
            result.push_back(to_string(cur));
        } else {
            result.push_back(to_string(cur) + "->" + to_string(nums[i]));
        }
    }
    return result;
}

int main(int argc, const char *argv[]) {
    vector<int> test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(4);
    test.push_back(5);
    test.push_back(7);
    vector<string> result = summaryRanges(test);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
