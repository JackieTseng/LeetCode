/*********************************************************************************
 * Leetcode : Pascal's Triangle II -- https://leetcode.com/problems/pascals-triangle-ii/ 
 * Coded in Oct 26th, 2015
 *
 * [Problem]
 * Given an index k, return the kth row of the Pascal's triangle.
 * 
 * For example, given k = 3,
 * Return [1,3,3,1].
 * 
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space? 
 *********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

// Solution One
vector<int> getRow(int rowIndex) {
	vector<int> result(rowIndex + 1, 1);
	for (int i = 0; i < rowIndex - 1; i++) {
		int cur = result[0];
		for (int j = 1; j < i + 2; j++) {
			int temp = cur + result[j];
			cur = result[j];
			result[j] = temp;
		}
	}
	return result;
}

// Solution Two
vector<int> getRow(int rowIndex) {
	vector<int> result(rowIndex + 1, 1);
	for (int i = 1; i < rowIndex; i++) {
		for (int j = i; j >= 1; j--) {
			result[j] += result[j - 1];
		}
	}
	return result;
}

int main() {
	int n;
	while (cin >>n) {
		vector<int> t = getRow(n);
		cout << "[";
		for (int i = 0; i < t.size(); i++) {
			cout << t[i];
			if (i != t.size() - 1) {
				cout << ",";
			}
		}
		cout << "]" << endl;
	} 
}
