
#include <iostream>
#include <algorithm>
#include <vector>
/*
    Graph + DFS:
    Given a list of 3-d points [(1,2,5), (5,3,2), ...., ] and a distance K
    If point A and point B are within K distance, group them together. If distance(A, B) <= K and distance (B,C) <= K, group A, B, C together.
    Return a list of groups.
*/

using namespace std;
bool distance_smaller_k (vector<int> p1, vector<int> p2, int k) {
    double x_2 = (p1[0] - p2[0])*(p1[0] - p2[0]);
    double y_2 = (p1[1] - p2[1])*(p1[1] - p2[1]);
    double z_2 = (p1[2] - p2[2])*(p1[2] - p2[2]);
    
    double distance = x_2 + y_2 + z_2;
    return distance <= k*k; 
}

void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<bool>& visited, int index) {
    if (visited[index]) return;
    if (graph[index].empty()) return;
    visited[index] = true;
    ans.back().push_back(index);
    
    // Iterate through the specific graph with index
    for (int i = 0 ; i < graph[index].size() ; ++i) {
        dfs(graph, ans, visited, graph[index][i]);
    }
}

vector<vector<int>> graph_DFS (vector<vector<int>> input, int k) {
    vector<vector<int>> graph(input.size(), vector<int>()); // List of indices
    vector<vector<int>> ans{{}}; // Group of points indices
    vector<bool> visited(input.size());
    
    // Construct the graph
    for (int i = 0 ; i < input.size() ; ++i) {
        for (int j = i + 1 ; j < input.size() ; ++j) {
            if (distance_smaller_k(input[i], input[j], k)) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    // Check the graph
    // for (auto& a : graph) {
    //     for (auto& b : a) {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    
    // Do dfs
    for (int i = 0 ; i < graph.size() ; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        ans.back().push_back(i);
        if (graph[i].empty()) continue;
        
        for (int j = 0 ; j < graph[i].size() ; ++j) {
            if (visited[graph[i][j]]) continue;
            dfs(graph, ans, visited, graph[i][j]);
        }
        ans.push_back({});
    }
    return ans;
}
int main () {
    vector<vector<int>> input = {{0,0,0},{2,2,0},{1,0,1}, {9,1,1}, {9,2,2}};
    vector<vector<int>> ans = graph_DFS(input, 6);
    cout << endl;
    for (auto& a : ans) {
        for (auto& i : a) {
            cout << i << " ";
        }
        cout << endl;
    }
}
