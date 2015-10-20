/*********************************************************************************
 * Leetcode : Find Median from Data Stream -- https://leetcode.com/problems/find-median-from-data-stream/
 * Coded in Oct 20th, 2015
 *
 * [Problem]
 * Median is the middle value in an ordered integer list. If the size of the list
 * is even, there is no middle value. So the median is the mean of the two middle value.
 * 
 * Examples: 
 * [2,3,4] , the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data structure.
 * double findMedian() - Return the median of all elements so far.
 * For example:
 * 
 * add(1)
 * add(2)
 * findMedian() -> 1.5
 * add(3) 
 * findMedian() -> 2 
 *********************************************************************************/
#include <functional>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
	public:
    	void addNum(int num) {
			if (small.empty() && large.empty()) {
				small.push(num);
			} else {
				double mid = findMedian();
				if (num < mid) {
					small.push(num);
					if (small.size() - large.size() > 1) {
						large.push(small.top());
						small.pop();
					}
				} else {
					large.push(num);
					if (large.size() - small.size() > 1) {
						small.push(large.top());
						large.pop();
					}
				}
			}
    	}

    	double findMedian() {
			if (small.empty() && large.empty()) {
				return 0;
			} else if (small.size() == large.size()) {
				return (small.top() + large.top()) / 2.0;
			} else {
				return small.size() > large.size() ? small.top() : large.top();
			}
		}
    private:
		priority_queue<int, vector<int>, greater<int> > large;
		priority_queue<int, vector<int>, less<int> > small;
}; 

int main() {
	MedianFinder mf;
	mf.addNum(1);
	cout << mf.findMedian() << endl;
	mf.addNum(2);
	cout << mf.findMedian() << endl;
	mf.addNum(3);
	cout << mf.findMedian() << endl;
	return 0;
}
