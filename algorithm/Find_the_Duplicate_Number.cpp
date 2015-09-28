#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int size = nums.size();
    int l = 1, h = size - 1, mid, counter;
    while (l < h) {
        mid = (l + h) / 2;
        counter = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] <= mid) {
                counter += 1;
            }
        }
        if (counter > mid) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
    
int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(2);
	cout << findDuplicate(nums) << endl;
	return 0;
}
