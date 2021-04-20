// Compiled with: g++ -Wall -std=c++14 -pthread
/*

Given a MxN matrix where each element can either be 0 or 1. We need to find the shortest path between a given source cell to a destination cell, or return -1 if no path can be founded. The path can only be created out of a cell if its value is 1. Here we apply the typical 4-direction movement(up/down/left/right).

The given matrix(M=4,N=4):
1 0 0 0
0 1 0 1
1 1 0 1
0 0 0 1


Source cell:
(0,3)


Destination cell:
(3,0)

The shortest distance will be 6.
*/

#include <iostream>

using namespace std;
int get_distance(vector<vector<int>> matrix, vector<int> source, vector<int> destination) {
    if (matrix.empty() || matrix[0].empty()) {return 0;}
    const int m = matrix.size(), n = matrix[0].size();
    queue<pair<int, int>> q; // x, y
    vector<int> ans(destination.size());
    q.push({source[0], source[1]});
    
    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    int steps = 0;
    // BFS
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0 ; i < size ; ++i) {
            auto tmp = q.front(); q.pop();
            for (auto& dir : dirs) {
                int x = dir[0] + tmp.first, y = dir[1] + tmp.second;
                if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == 1 || matrix[x][y] == -1) continue;
                for (auto& des : destination) {
                    if (x == des[0] && y == des[1]) step+1;
                }
                matrix[x][y] = -1;
                q.push({x,y});
            }
        }
        steps++;
    }
    
    return ans;
}

int main(){
    cout << "Hello, World!" << endl;
    vector<int> source = {0,3};
    vector<int> destination = {{3,0,id1},{x2,y2, id2}, {x3,y3, id3}};

    cout << get_distance(source, destination);
    vector<int> check;
    for (auto& s : source) {
        vector<int> d = destination;
        d.erase(s);
        check.push_back(get_distance(s, d));
    }
    cout << *min_element(check.begin(), check.end());
    
    return 0;
}



