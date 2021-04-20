#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (nums.empty()) return;
        // if (nums.size() == 1) return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + (k));
        reverse(nums.begin() + k, nums.end());
    }
    // O(n), space O(1)
    int shiftDifference (vector<int> a, vector<int> b) {
        int p1 = 0, count = 0;
        while (a[0] != b[p1]) {
            p1++;
            count++;
            p1 %= a.size();    
        }
    }
};