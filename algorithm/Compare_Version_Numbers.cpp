/*********************************************************************************
 * Leetcode : Compare Version Numbers -- https://leetcode.com/problems/compare-version-numbers/
 * Coded in Aug 31st, 2015
 *
 * [Problem]
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 * 
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level
 * revision of the second first-level revision.
 * 
 * Here is an example of version numbers ordering:
 * 
 * 0.1 < 1.1 < 1.2 < 13.37
 *********************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

int compareVersion(string version1, string version2) {
    int length1 = version1.length(), length2 = version2.length(), i;
    int lasIndex1 = 0, lasIndex2 = 0, curIndex1 = 0, curIndex2 = 0;
    while (lasIndex1 < length1 || lasIndex2 < length2) {
        char num1[10], num2[10];
        int v1, v2;
        if (curIndex1 != length1) {
            for (i = lasIndex1; i < length1; i++) {
                if (version1[i] == '.') {
                    curIndex1 = i;
                    break;
                }
            }
            if (i == length1) {
                curIndex1 = length1;
            }
            strncpy(num1, version1.c_str() + lasIndex1, (curIndex1 - lasIndex1));
            num1[curIndex1 - lasIndex1] = '\0';
            lasIndex1 = curIndex1 + 1;
            v1 = atoi(num1);
        } else {
            v1 = 0; 
        }
        if (curIndex2 != length2) {
            for (i = lasIndex2; i < length2; i++) {
                if (version2[i] == '.') {
                    curIndex2 = i;
                    break;
                }
            }
            if (i == length2) {
                curIndex2 = length2;
            }
            strncpy(num2, version2.c_str() + lasIndex2, (curIndex2 - lasIndex2));
            num2[curIndex2 - lasIndex2] = '\0';
            lasIndex2 = curIndex2 + 1;
            v2 = atoi(num2);
        } else {
            v2 = 0;
        }
        if (v1 < v2) {
            return -1;
        } else if (v1 > v2) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, const char *argv[]) {
    string v1, v2;
    while (cin >> v1 >> v2) {
        cout << compareVersion(v1, v2) << endl;
    }
    return 0;
}
