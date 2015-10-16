/*********************************************************************************
 * Leetcode : Pascal's Triangle -- https://leetcode.com/problems/pascals-triangle/ 
 * Coded in Oct 16th, 2015
 *
 * [Problem]
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * For example, given numRows = 5,
 * Return
 * 
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ] 
 *********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows) {
	vector<vector<int> > triangle;
	for (int i = 0; i < numRows; i++) {
		triangle.push_back(vector<int>(1, 1));
		if (i) {
			for (int j = 1; j < i; j++) {
				triangle[i].push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
			}
			triangle[i].push_back(1);
		}
	}
	return triangle;
}

int main() {
	vector<vector<int> > temp = generate(5);
	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < temp[i].size(); j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
} 
