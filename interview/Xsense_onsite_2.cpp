// Second interview with Nicholas Hausch

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
  int m = nums.size() , n = nums[0].size();
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
  // vector<vector<int>> input = {{3, 5}, {7, 9}, {3, 7}, {8, 8}};
  // int r = 4, c = 2;
  // vector<vector<int>> output(r, vector<int>(c));
  // output = reshapematrix(input, r, c);
  // int m = output.size() , n = output[0].size();
  // for (int i = 0 ; i < m ; ++i) {
  //   for (int j = 0 ; j < n ; ++j) {
  //     cout << output[i][j] << ", ";
  //   }
  //   cout << endl;
  // }
  // return 0;
  vector<int> input = {4, 6, 9, -3, 5, 10};
  int k = 3;
  cout << slidingwindow(input, k);
}