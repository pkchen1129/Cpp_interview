1. 
ListNode {
 Int val;
 ListNode* next;
}

Input (ListNode*):
1->2->3->X

Output (ListNode*):
3->2->1->X

ListNode* func(ListNode* root) {
  ListNode* prev = NULL, * cur = root, *n = root;
  while (cur) {
     n = cur->next;
     cur->next = prev;
     prev = cur;
     cur = n;
  }
  return prev;
}


2.
Input: grid
1 0 0 1 1
0 0 0 1 1
1 1 0 1 1
0 1 0 1 1

// Output:3
int func (vector<vector<int>>& grid) {
  vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
  int m = grid.size(), n = grid[0].size();
  vector<vector<bool>> visited(m,vector<bool>(n,false));
  int ans = 0;
  for (int i = 0 ; i < m ; ++i) {
    for(int j = 0 ; j < n ; ++j){
      if (grid[i][j] ==  0 || visited[i][j]) continue; 
      ans++;
      dfs(grid, i, j, visited);
    }
  }
  return ans;
}


void dfs (vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || visited[i][j]) return;
    visited[i][j] = true;
    for (auto& dir : dirs) {
        int x = i + dir[0], y = j + dir[1];
        dfs(grid, x, y, visited);
    }
}


