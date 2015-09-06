#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Solution One
bool containsDuplicate(vector<int>& nums) {
    map<int, bool> hTable;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (hTable.find(nums[i]) == hTable.end()) {
            hTable[nums[i]] = true;
        } else {
            return true;
        }
    } 
    return false;
}

int main(int argc, const char *argv[]) {
    vector<int> test;
    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        test.push_back(t);
    }
    cout << (containsDuplicate(test) ? "Yes" : "No") << endl;
    return 0;
}
