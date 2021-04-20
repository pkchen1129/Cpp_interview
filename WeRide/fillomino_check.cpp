// https://www.kakuro-online.com/fillomino/
// 2 * 1
// 1 * 3
// 2 2 *

// 2 3 6 6 6
// 2 3 5 6 6
// 1 3 5 6 4
// 3 1 5 4 4
// 3 3 5 5 4

#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& grid, int i, int j, int target, int& curCnt) {
    const int m = grid.size();
    const int n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != target) return true; // no overflow
    if (grid[i][j] == -1) return true;
    ++curCnt;
    grid[i][j] = -1;
    dfs(grid, i - 1, j, target, curCnt);
    dfs(grid, i + 1, j, target, curCnt);
    dfs(grid, i, j - 1, target, curCnt);
    dfs(grid, i, j + 1, target, curCnt);
    return curCnt == target;
}

bool check(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return true;
    const int m = grid.size();
    const int n = grid[0].size();
   
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int curCnt = 0;
            if (grid[i][j] == -1) continue;
            if (!dfs(grid, i, j, grid[i][j], curCnt)) return false; 
        }
    }
    return true;
}


int main() {
    //vector<vector<int>> grid{{2, 2, 1}, {1, 3, 3}, {2, 2, 3}};
    //vector<vector<int>> grid{{1, 2, 1}, {1, 3, 3}, {2, 2, 3}};
    //vector<vector<int>> grid{{2, 1}};
    vector<vector<int>> grid{{2, 3, 6, 6, 6}, {2, 3, 5, 6, 6}, {1, 3, 5, 6, 4}, {3, 1, 5, 4, 4}, {3, 3, 5, 5, 4}};
    cout << check(grid);
    return 0;
}
