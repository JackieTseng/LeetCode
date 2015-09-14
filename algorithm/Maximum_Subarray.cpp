#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Solution One
int maxSubArray(vector<int>& nums) {
    int size = nums.size(), ans = nums[0];
    for (int i = 0, sum = 0; i < size; i++) {
        sum += nums[i];
        ans = max(sum, ans);
        sum = max(sum, 0);
    }
    return ans;
}

int main(int argc, const char *argv[]) {
    int t[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; 
    vector<int> temp = vector<int>(t, t + (sizeof(t) / sizeof(int)));
    cout << maxSubArray(temp) << endl;
    return 0;
}
