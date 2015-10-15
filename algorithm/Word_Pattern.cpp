/*********************************************************************************
 * Leetcode : Word Pattern -- https://leetcode.com/problems/word-pattern/ 
 * Coded in Oct 15th, 2015
 *
 * [Problem]
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a letter
 * in pattern and a non-empty word in str.
 * 
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains lowercase
 * letters separated by a single space. 
 *********************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool wordPattern(string pattern, string str) {
	map<char, string> hashTable;
    int l = pattern.length();
	stringstream ss(str);
    for (int i = 0; i < l; i++) {
        ss >> str;
		char key = pattern[i];
		if (hashTable.find(key) == hashTable.end()) {
			for (map<char, string>::iterator it = hashTable.begin(); it != hashTable.end(); it++) {
				if (str == it->second) {
					return false;
				}
			}
			hashTable[key] = str;
		} else {
			if (str != hashTable[key]) {
				return false;
			}
		}
    }
    if (ss >> str) {
        return false;
    }
    return true;
}

int main () {
	string p = "abba", s = "dog cat cat dog";
	cout << (wordPattern(p, s)? "Yes" : "No") << endl;
	return 0;
}
