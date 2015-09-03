/*********************************************************************************
 * Leetcode : Gray Code -- https://leetcode.com/problems/gray-code/
 * Coded in Seq 3rd, 2015
 *
 * [Problem]
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the code,
 * print the sequence of gray code. A gray code sequence must begin with 0.
 * 
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * 
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 * 
 * For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that. 
 *********************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> grayCode(int n) {
    vector<int> result;
    int total = pow(2, n);
    for (int i = 0; i < total; i++) {
        // Gray code -> binary code
        result.push_back(i ^ (i >> 1));
    }
    return result;
}

int binaryToGray(int n) {
    return n ^ (n >> 1);
}

int grayToBinary(int n) {
    int r = n;
    while (n >>= 1) {
        r ^= n;
    }
    return r;
}

int main(int argc, const char *argv[]) {
    int t;
    while (cin >> t) {
        vector<int> r = grayCode(t);
        for (int i = 0; i < r.size(); i++) {
            cout << r[i] << endl; 
        }
        cout << endl;
    } 
    return 0;
}
