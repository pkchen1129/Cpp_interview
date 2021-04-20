/*
Find the start index of the longest overlapping continuous subarray in two given integer arrays.

{1, 2, 3, 4, 5}
{2, 3, 4, 3, 1}
=> index = 1

{1, 2, 3, 4, 5}
{20, 21}
=> index = -1

*/
#include <iostream>
#include <vector>
using namespace std;

int overlap(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() || nums2.empty()) return -1;
    
    const int n = nums1.size();
    const int m = nums2.size();
    pair<int, int> res; // len, idx
    res.first = -1;
    res.second = -1;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (nums2[j] == nums1[i]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                
                if (num2[j - 1] == nums[i - 1])
                int len = 0;
                while((j + len < m) && (i + len < n) && (nums2[j + len] == nums1[i + len])) {
                    ++len;
                }
                if (len > res.first) {
                    res.first = len;
                    res.second = i;
                }
            }
        }
    }
    return res.second;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {20, 21};
    cout << overlap(nums1, nums2);
    
    
    return 0;
    
}

int overlap(vector<int>& nums1, vector<int>& nums2) {
    // Sort the array
    // Iterate and get the longest continuous
}