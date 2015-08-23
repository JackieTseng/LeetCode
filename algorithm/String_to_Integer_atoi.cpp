/*********************************************************************************
 * Leetcode : String to Integer (atoi) -- https://leetcode.com/problems/string-to-integer-atoi/
 * Coded in Aug 23th, 2015
 *
 * [Problem]
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge, please
 * do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
 * You are responsible to gather all the input requirements up front.
 * 
 * [Requirements for atoi]
 * The function first discards as many whitespace characters as necessary until the first
 * non-whitespace character is found. Then, starting from this character, takes an optional
 * initial plus or minus sign followed by as many numerical digits as possible, and interprets
 * them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral number,
 * which are ignored and have no effect on the behavior of this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid integral number,
 * or if no such sequence exists because either str is empty or it contains only whitespace
 * characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. If the correct value
 * is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648)
 * is returned.
 *********************************************************************************/
#include <iostream>
#include <limits.h>
using namespace std;

int myAtoi(string str) {
    int index = 0;
    while (str[index] == ' ' || str[index] == '\t') {
        ++index;
    }
    int flag = 0;
    if (str[index] == '-' || str[index] == '+') {
        flag = (str[index++] == '-')? -1 : 1;
    }
    int result = 0, length = str.length();
    for (; index < length && str[index] >= '0' && str[index] <= '9'; ++index) {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[index] - '0' > 7)) {
            if (flag == 0 || flag == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }
        result = result * 10 + (str[index] - '0' );
    }
    return ((flag == 0)? 1 : flag) * result;
}

int main(int argc, const char *argv[]) {
    string a;
    while (cin >> a) {
        cout << myAtoi(a) << endl;
    }
    return 0;
}
