#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int array[1000000] = {0}, index[1000000] = {0}, size = nums.size();
    for (int i = 0; i < size; i++) {
        array[nums[i]] = 1; 
        index[nums[i]] = i + 1;
    }
    for (int i = 0; i < size; i++) {
        if (array[target - nums[i]] == 1) {
            vector<int> result;
            result.push_back(i + 1);
            result.push_back(index[target - nums[i]]);
            return result;
        }
    }
}

int main(int argc, const char *argv[]) {
    vector<int> test;
    test.push_back(2); 
    test.push_back(7); 
    test.push_back(11); 
    test.push_back(15);
    vector<int> result = twoSum(test, 9);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
