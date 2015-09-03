/*********************************************************************************
 * Leetcode : Reverse Bits -- https://leetcode.com/problems/reverse-bits/
 * Coded in Seq 3rd, 2015
 *
 * [Problem]
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
 * return 964176192 (represented in binary as 00111001011110000010100101000000).
 * 
 * Follow up:
 * If this function is called many times, how would you optimize it?
 * 
 * Related problem: Reverse Integer 
 *********************************************************************************/
#include <iostream>
using namespace std;
#define uint32_t int

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; ++i, n >>= 1) {
        result <<= 1;
        result |= (n & 1);
    }
    return result;
}

int main(int argc, const char *argv[]) {
    uint32_t temp;
    while (cin >> temp) {
        cout << reverseBits(temp) << endl;
    } 
    //cout << reverseBits(43261596) << endl;
    return 0;
}
