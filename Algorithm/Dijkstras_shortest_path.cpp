/**
  Including printing the path out, use a parent to store the paths
**/
#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <bits/stdc++.h> 
using namespace std;
typedef pair<int,int> P;
class Dij{
public:
    Dij(int nn, int s)
    : node_num(nn) 
    , source(s)
    {
        
    }
    int node_num;
    int source;
    set<P> s;
    

    void dij_algorithm(vector<vector<pair<int,int>>> graph, vector<vector<int>>& parent){
        vector<int> dist(node_num,INT_MAX);

        dist[0] = 0;
        s.insert(make_pair(0,source));
        parent[0] = {-1}; // !!!!!!!!!!!!!!!
        while(!s.empty()){
            P source_pair = *s.begin();
            s.erase(s.begin());

            int source_node = source_pair.second;
            for(auto& neighbor : graph[source_node]){
                int neighbor_node = neighbor.first;
                int dis_to_n = neighbor.second;
                if(dist[neighbor_node] > dis_to_n + dist[source_node]){
                    // If the distance to the adjacent node is not INF, means the pair <dist, node> is in the set
                    // Remove the pair before updating it in the set.
                    if(dist[neighbor_node] != INT_MAX){
                        // Remove the neighbor
                        s.erase(s.find(make_pair(dist[neighbor_node],neighbor_node)));
                    }
                    dist[neighbor_node] = dis_to_n + dist[source_node];
                    parent[neighbor_node].clear();
                    parent[neighbor_node].push_back(source_node);
                    s.insert(make_pair(dist[neighbor_node],neighbor_node));
                }
                else if(dist[neighbor_node] == dis_to_n + dist[source_node]){
                    parent[neighbor_node].push_back(source_node);
                }
            }
        }
    }

    // Using a recursive to recurssively tracks different path with parents vector
    void find_paths(vector<vector<int> >& paths, vector<int>& path, vector<vector<int>>& parent, int n, int dest) 
    { 
        // Base Case 
        if (dest == -1) { 
            paths.push_back(path); 
            return; 
        }
        // Start iterate from 5, 
        for (int par : parent[dest]) { 
    
            // Insert the current vertex in path 
            path.push_back(dest); 
            
            // Recursive call for its parent 
            find_paths(paths, path, parent, n, par); 
    
            // Remove the current vertex 
            path.pop_back(); 
        } 
    } 
};



int main(){
    vector<vector<pair<int,int>>> graph;
    // Node 0: <1,5> <2,1> <3,4>
    graph.push_back({{1,5}, {2,1}, {3,3}});

    // Node 1: <0,5> <2,3> <4,8>
    graph.push_back({{0,5}, {2,3}, {4,8}});

    // Node 2: <0,1> <1,3> <3,2> <4,1>
    graph.push_back({{0,1}, {1,3}, {3,2}, {4,1}});

    // Node 3: <0,4> <2,2> <4,2> <5,1>
    graph.push_back({{0,4}, {2,2}, {4,2}, {5,1}});

    // Node 4: <1,8> <2,1> <3,2> <5,3>
    graph.push_back({{1,8}, {2,1}, {3,2}, {5,3}});

    // Node 5: <3,1> <4,3> 
    graph.push_back({{3,1}, {4,3}});
    
    int size = graph.size();
    int s = 0;

    vector<vector<int> > paths; 
	vector<int> path; 
	vector<vector<int>> parent(size,vector<int>()); 


    Dij algorithm(size,s);
    algorithm.dij_algorithm(graph, parent);

    for (int i = 0 ; i < size ; ++i){
        cout << "i = " << i << ":";
        for (auto& out : parent[i]){
           cout << out << ",";
        }
        cout << endl;
    }
    algorithm.find_paths(paths, path, parent,size, size-1);
    
    for (auto v : paths) { 

		// Since paths contain each path in reverse order, so reverse it 
		reverse(v.begin(), v.end()); 

		// Print node for the current path 
		for (int u : v) 
			cout << u << " "; 
		cout << endl; 
	}
    
}