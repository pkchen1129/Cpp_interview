#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // To sparse
    vector<vector<int>> toSparse(vector<vector<int>>& A) {
        vector<vector<int>> res;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                if (A[i][j] == 0) continue;
                res.push_back({i, j, A[i][j]});
            }
        }
        return res;
    }

    // Element-wise multiplication method
    void cal(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& res) {
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                int ai = A[i][0], ak = A[i][1], aik = A[i][2];
                int bk = B[j][0], bj = B[j][1], bkj = B[j][2];
                if (ak == bk) // Important method (Matrix Multiplication)
                    res[ai][bj] += aik * bkj;
            }
        }
    }
    
    void cal_plus(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& res) {
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                int ai = A[i][0], ak = A[i][1], aik = A[i][2];
                int bk = B[j][0], bj = B[j][1], bkj = B[j][2];
                if (ai == bk && ak == bj) 
                    res[ai][bj] += aik + bkj;
            }
        }
    }

    // Main : tosparse -> multiply
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.empty() || B.empty()) return {};
        const int m = A.size();
        const int k = A[0].size();
        const int n = B[0].size();
        vector<vector<int>> A_sparse = toSparse(A);
        vector<vector<int>> B_sparse = toSparse(B);
        vector<vector<int>> res(m, vector<int> (n));
        cal(A_sparse, B_sparse, res);
        return res;
    }
    // tosparse -> addition
    vector<vector<int>> plus(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.empty() || B.empty()) return {};
        if (A.size() != B.size() || A[0].size() != B[0].size()) return {{}};
        const int m = A.size();
        const int n = A[0].size();
        vector<vector<int>> A_sparse = toSparse(A);
        vector<vector<int>> B_sparse = toSparse(B);
        vector<vector<int>> res(m, vector<int> (n));
        cal(A_sparse, B_sparse, res);
        return res;
    }


};