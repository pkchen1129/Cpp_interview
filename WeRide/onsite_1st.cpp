// Compiled with: g++ -Wall -std=c++14 -pthread

// Is Bipartite Graph
// given {{1, 4}, {2, 5}, {3, 6}, {1, 5}}
// return true/false

// 1, 2, 3
// 4, 5, 6

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool biparite(vector<vector<int>>& graph) {
    int size = graph.size();
    vector<int> diff_color(size); 
    // uncolored: 0
    // colored_a: 1
    // colored_b: -1
    queue<int> q;
    
    for (int i = 0 ; i < size ; ++i) {
        // Check whether having the color
        if(diff_color[i]) continue; // have that color
        diff_color[i] = 1; 
        
        // BFS
        
        q.push(i); 
        while (!q.empty()) {
            int tmp = q.front(); q.pop();
            for (int neighbor : graph[tmp]) {
                // if uncolored
                if (!diff_color[neighbor]) {
                    // colored
                    diff_color[neighbor] = diff_color[tmp] * (-1);
                    q.push(neighbor);
                }
                // colored
                else if(diff_color[neighbor] == diff_color[tmp]) {
                    return false;
                }
            }
        }
        
    }
    return true;
}

int main(){
    cout << "Hello, World!" << endl;
    vector<vector<int>> graph = {{1, 4}, {2, 5}, {3, 6}, {1, 5}};
    cout << biparite(graph) << endl;
    return 0;
}