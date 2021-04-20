/**
 * @file Xsense_onsite_PoKangChen.cpp
 * @author Po-Kang Chen (pkchen@umich.edu)
 * @brief follow-up for the interviews on 3/3 with Peng Xu
 * @date 2021-03-06
 * 
 * 
 */


// First interview 

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Brute force 
// time:O(2^n), space:O(1)
class CodeSolution {
public:
    bool Partition(vector<int>& nums) {
        int sum = 0;
        for (auto& num : nums) sum += num; 
        if (sum % 2 != 0) return false;
        return dfs(nums, sum / 2, 0);
    }
    bool dfs (vector<int>& nums, int target, int level) {
        if (target == 0) return true;
        if (target < 0) return false;
        if (level == nums.size()) return false;
        return dfs(nums, target - nums[level], level+1) || dfs(nums, target, level+1);
    }
};

// DP 
// time:O(m*n), space:O(m)
class CodeSolution {
public:
    bool Partition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum >> 1;
        if(sum & 1)return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for(auto num : nums){
            for(int i = target ; i >= num ; --i){
                if(dp[target]) return true;
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[target];
    }
};



int main () {
    CodeSolution s;
    vector<int> input;
    // Case 1: 12,2,5,5 = true
    input = {12,2,5,5};
    cout << s.Partition(input) << endl;
    
    // Case 2: 15,20 = false
    input = {15,20};
    cout << s.Partition(input) << endl;
    
    // Case 3: 2,2,2,2,3  = false
    input = {2,2,2,2,3};
    cout << s.Partition(input) << endl;
}







/** Second interview with Nicholas Hausch**/

// Reshape matrix
// Inputs: array of ints nums, new row size r, new column size c
// Example:
// [[3, 5], [7, 9]], r = 1, c = 4
// Outputs [[3], [5], [7], [9]]

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// To execute C++, please define "int main()"
vector<vector<int>> reshapematrix (vector<vector<int>>& nums, int r, int c) {
    // Check the size: r*c == original m * n;
    int m = nums.size() ,n = nums[0].size();
    if (m * n != r * c) return nums;
    
    // Do two for loops do the reshape
    vector<vector<int>> ans (r, vector<int>(c));
    for (int i = 0 ; i < r ; ++i) {
        for (int j = 0 ; j < c ; ++j) {
            int z = i * c + j;
            ans[i][j] = nums[z / n][z % n];
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> input = {{3, 5}, {7, 9}, {3, 7}, {8, 8}};
    int r = 4, c = 2;
    vector<vector<int>> output(r, vector<int>(c));
    output = reshapematrix(input, r, c);
    int m = output.size() , n = output[0].size();
    for (int i = 0 ; i < m ; ++i) {
        for (int j = 0 ; j < n ; ++j) {
            cout << output[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}


// Find max average subarray
// Inputs are 1d array of ints, int k
// [4, 6, 8, -3, 5, 10] k = 3
// return 9

double slidingwindow (vector<int>& input, int k) {
    double ans = -1000000;
    // Brute Force
    for (int i = 0 ; i <= (int)input.size() - k; ++i) {
        int sum = 0;
        for (int j = i ; j < k; ++j) {
            sum += input[j];
        }
        ans = max(((double)sum / k), ans);
    }
    return ans;
}


int main() {
    vector<int> input = {4, 6, 9, -3, 5, 10};
    int k = 3;
    cout << slidingwindow(input, k);
}



















/**
 * 
 * 
 */
// Given the polygon vertices and a point, how would we know it's inside or outside the polygon.

struct Point{
    double _x;
    double _y;  
    Point(double x, double y) : _x(x), _y(y) {}
};
class Solution
{
public:
    bool checkiswithin (Point A, Point B, Point P) {
    if ((A._x - P._x) * (P._x - B._x) > 0) return true; // same sign
    else return false;
    }
    bool solve (vector<Point> polygon, Point P_in) {
        int count = 0;
        for (int i = 0 ; i < polygon.size() - 1 ; ++i) {
            Point A = polygon[i];
            Point B = polygon[i+1];
            Point P(0,0);
            // if horizontal line
            if (A._y == B._y) {
                continue;
            }
            // if vertical line
            else if (A._x == B._x) {
                count++;
                continue;
            }
            else {
                double m = (A._y - B._y) / (A._x - B._x);
                double c = A._y - m * A._x;

                P._x = (P_in._y - c) / m;
                P._y = P_in._y;
                if (checkiswithin (A, B, P)) count++;   
            }

        }
        cout << "count: "<< count << endl;
        if (count == 1) return true;
        return false;
    }
};

int main () {
    
    /* Triangle case: p1(0,0), p2(1,0), p3(0.5,1) */
    Solution triangle;
    Point P_in1(0.5, 1.5);
    Point P_in2(0.5, 0.5);
    Point P_in3(0  , 0.5);
    
    vector<Point> input = {Point(0,0), Point(1,0), Point(0.5, 1)};
    // cout << triangle.solve(input, P_in1) << endl;
    // cout << triangle.solve(input, P_in2) << endl;
    cout << triangle.solve(input, P_in3) << endl;
}








