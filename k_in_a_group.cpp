#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool distance_smaller_k (vector<int> p1, vector<int> p2, int k) {
    double distance = (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]) + (p1[2] - p2[2])*(p1[2] - p2[2]);
    return distance <= k*k; 
}
void graph_DFS (vector<vector<int>> input, int k) {
    vector<vector<int>> graph(input.size(), vector<int>()); // List of indices
    vector<vector<int>> ans; // List of points
    vector<bool> visited(input.size());
    // Construct the graph
    for (int i = 0 ; i < input.size() ; ++i) {
        for (int j = i ; j < input[0].size() ; ++j) {
            if (distance_smaller_k(input[i], input[j], k)) {
                graph[i].push_back(j);
            }
        }
    }
    for (int i = 0 ; i < input.size() ; ++i) {
        for (int j = 0 ; j < input[i].size() ; ++j) {
            dfs(graph, ans, visited, input[i][j]);
        }
        ans.push_back({});
        
    }
}
void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<bool>& visited, int index) {
    if (visited[index]) return;
    visited[index] = true;
    ans.back().push_back(index);
    for (int i = 0 ; i < graph[index].size() ; ++i) {
        if (visited[graph[index][i]]) continue;
        dfs(graph, ans, visited, graph[index][i]);
    }
}