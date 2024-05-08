#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        int timer = 0;
    
        void dfs(int node, int parent, vector <int> adj[], vector <int> &visited, vector <int> &tin, vector <int> &low, vector <int> &marked) {
            visited[node] = 1;
            tin[node] = low[node] = timer++;
            
            int children = 0;
            
            for (auto adjNode: adj[node]) {
                if (adjNode == parent) continue;
                
                if (!visited[adjNode]) {
                    dfs(adjNode, node, adj, visited, tin, low, marked);
                    low[node] = min(low[node], low[adjNode]);
                    
                    // check for articulation node
                    if (low[adjNode] >= tin[node] && parent != -1) {
                        marked[node] = 1;
                    } 
                    
                    children++;
                }
                
                else {
                    low[node] = min(low[node], tin[adjNode]);
                }
            }
            
            if (children > 1 && parent == -1) marked[node] = 1;
        }
    
    public:
        vector<int> articulationPoints(int V, vector<int>adj[]) {
            vector <int> visited(V, 0);
            vector <int> tin(V);
            vector <int> low(V);
            vector <int> marked(V, 0);
            vector <int> ans;
            
            for (int i = 0; i < V; i++) {
                if (!visited[i]) {
                    dfs(i, -1, adj, visited, tin, low, marked);
                }
            }
            
            for (int i = 0; i < V; i++) {
                if (marked[i]) {
                    ans.push_back(i);
                }
            }
            
            if (ans.size() == 0) {
                return {-1};
            }
            
            return ans;
        }
};