/*********************************************************************************
 * Leetcode : Add Binary -- https://leetcode.com/problems/add-binary/ 
 * Coded in Oct 25th, 2015
 *
 * [Problem]
 * Given two binary strings, return their sum (also a binary string).
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100". 
 *********************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string addBinary(string a, string b) {
	int la = a.length(), lb = b.length();
	int l = la > lb? la : lb;
	string result;
	vector<int> numA(l, 0), numB(l, 0);
	for (int i = la - 1, t = 0; t < la; i--, t++) {
		numA[t] = a[i] - '0';
	}
	for (int i = lb - 1, t = 0; t < lb; i--, t++) {
		numB[t] = b[i] - '0';
	}
	int last = 0, sum = 0;
	for (int i = 0; i < l; i++) {
		int sum = numA[i] ^ numB[i] ^ last;
		//cout << numA[i] << " ^ " << numB[i] << " ^ " << last << " = " << sum << endl;
		last = ((numA[i] ^ numB[i]) && last) || (numA[i] && numB[i]);
		//cout << numA[i] << " || " << numB[i] << " && " << last << " = " << last << endl;
		result.insert(result.begin(), sum + '0');
	}
	if (last) {
		result.insert(result.begin(), last + '0');
	}
	return result;
}

int main() {
	string a = "1010";
	string b = "1011";
	cout << addBinary(a, b) << endl;
	return 0;
} 
