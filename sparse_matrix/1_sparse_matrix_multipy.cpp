/*
 * A and B are vectors of coordinate-value tuples
 */
#include <tuple>
#include <iostream>
#include <vector>
using namespace std;
void multiply (vector<tuple<int,int,int>> &A, vector<tuple<int,int,int>> &B, vector<vector<int>> &res) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            int ai = get<0>(A[i]), aj = get<1>(A[i]), aval = get<2>(A[i]);
            int bi = get<0>(B[j]), bj = get<1>(B[j]), bval = get<2>(B[j]);
            if (aj == bi)
                res[ai][bj] += aval * bval;
        }
    }
}
//This still works with the problem as is, but running time is limited by finding the sparse values by scanning the dense grid.

void scan(vector<vector<int>> &grid, vector<tuple<int,int,int>> &pairs) {
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j]) pairs.push_back(make_tuple(i, j, grid[i][j]));
}

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    if (A.empty() || B.empty()) return {};
    vector<tuple<int,int,int>> ap, bp;
    scan(A, ap);
    scan(B, bp);
    vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
    multiply(ap, bp, res);
    return res;
}