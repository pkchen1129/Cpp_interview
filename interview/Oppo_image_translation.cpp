/*
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
            [0,1,0],
            [0,1,0]]
       B = [[0,0,0],
            [0,1,1],
            [0,0,1]]
       mat = [[9,6,0],
              []
							]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes: 

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1
*/
  
  
#include <iostream>
#include <vector>

int func (vector<vector<int>>& A, vector<vector<int>>& B) {
	// iterate through A
  if (A.empty() || A[0].empty()) return 0;
  if (B.empty() || B[0].empty()) return 0;
  
  unordered_map<pair<int, int>, int> M; // dirx, diry -> count;
  
	int m = A.size(), n = A[0].size();
	// int m_b = B.size(), n_b = B[0].size();
  vector<vector<int>> mat(2*m-2, vector<int>(2*n-2, 0));
  int global_count = 0;
  for (int i = 0 ; i < m ; ++i) {
  	for (int j = 0 ; j < n ++j) {
    	if (A[i][j] == 0) continue;
      // Iterate through B
      for (int k = 0 ; k < m ; ++k) {
      	for (int l = 0 ; l < n ; ++l) {
          if (B[i][j] == 0) continue;
        	int dis_x = k - i;
        	int dis_y = l - j;
          mat[dis_x][dis_y]++;
          
        }
      }
      // 
    }
  }
  // Iterate through mat, 
  
	for (int i = 0 ; i < 2*m-2 ; ++i) {
  	for (int j = 0 ; j < 2*m-2 ; ++j) {
      if (mat[i][j] == 0) continue;
      global_count = max (global_count, mat[i][j]);
    }
  }
  return global_count;
}