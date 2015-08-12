/*********************************************************************************
 * Leetcode : Single Number -- https://leetcode.com/problems/single-number/
 * Coded in Jul 1st, 2014
 *
 * [Problem]
 * Given an array of integers, every element appears twice except for one. Find
 * that single one.
 *
 * Notes:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *********************************************************************************/

int singleNumber(int A[], int n) {
    int num = A[0];
    for (int i = 1; i < n; ++i) {
        num ^= A[i];
    }
    return num;
}
