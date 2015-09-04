/*********************************************************************************
 * Leetcode : H-Index  -- https://leetcode.com/problems/h-index/
 * Coded in Seq 4th, 2015
 *
 * [Problem]
 * Given an array of citations (each citation is a non-negative integer) of a researcher,
 * write a function to compute the researcher's h-index.
 * 
 * According to the definition of h-index on Wikipedia: "A scientist has index h if h of
 * his/her N papers have at least h citations each, and the other N − h papers have no more
 * than h citations each."
 * 
 * For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5
 * papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
 * Since the researcher has 3 papers with at least 3 citations each and the remaining two
 * with no more than 3 citations each, his h-index is 3.
 * 
 * Note: If there are several possible values for h, the maximum one is taken as the h-index.
 * 
 * Hint:
 * 
 * An easy approach is to sort the array first.
 * What are the possible values of h-index?
 * A faster approach is to use extra space.
 *********************************************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Solution One
int hIndex(vector<int>& citations) {
    int size = citations.size(), h = size;
    sort(citations.begin(), citations.end());
    for (int i = size - 1; i >= 0; --i) {
        if (size - h >= 0 && citations[size - h] >= h) {
            if (size - h - 1 < 0 || (size - h - 1 >= 0 && citations[size - h - 1] <= h)) {
                break;
            }
        }
        --h;
    }
    return h;
}

// Solution Two
int hIndex(vector<int>& citations) {
    int size = citations.size();
    sort(citations.begin(), citations.end());
    for (int i = 0; i < len; i++) {
        if (citations[i] >= size - i) {
            return size - i;
        }
    }
    return 0;
}

int main(int argc, const char *argv[]) {
    vector<int> test;
    test.push_back(3);
    test.push_back(0);
    test.push_back(6);
    test.push_back(1);
    test.push_back(5);
    cout << hIndex(test) << endl;
    return 0;
}
