/*
    Summed-area table
    wiki: https://en.wikipedia.org/wiki/Summed-area_table
    Leetcode 304: https://leetcode.com/problems/range-sum-query-2d-immutable/
*/
#include <vector>
using namespace std;
class NumMatrix 
{
public:
    vector<vector<int>> dp;
    // Constructor
    NumMatrix (vector<vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty()) return; 
        dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1 ; i <= matrix.size() ; ++i ) {
            for (int j = 1 ; j <= matrix[0].size() ;++j) {
                dp[i][j] = matrix[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Since the dp is (matrix.size() + 1, matrix[0].size() + 1)
        // dp[row2 + 1][col2 + 1] - dp[row1 + 1 - 1][col2 + 1] - dp[row2 + 1][col1 + 1 - 1] + dp[row1 + 1 - 1][col1 + 1 - 1];
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
    
    
};