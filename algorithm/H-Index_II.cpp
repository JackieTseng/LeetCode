/*********************************************************************************
 * Leetcode : H-Index II --https://leetcode.com/problems/h-index-ii/ 
 * Coded in Seq 4th, 2015
 *
 * [Problem]
 * Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
 *
 * Hint:
 * 
 * Expected runtime complexity is in O(log n) and the input is sorted. 
 *********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int>& citations) {
    int size = citations.size();
    if (size == 0) {
        return 0;
    }
    int l = 0, r = size - 1; 
    while (l < r) {
        int m = (l + r) / 2;
        if (citations[m] < size - m) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    if (!citations[r]) {
        return 0;
    } else {
        return size - r;
    }
}

int main(int argc, const char *argv[]) {
    vector<int> test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(3);
    test.push_back(5);
    test.push_back(6);
    cout << hIndex(test) << endl;
    return 0;
}
