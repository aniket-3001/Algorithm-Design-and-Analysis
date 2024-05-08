#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 0;

    void dfs(int node, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<vector<int>>& ans, vector<int>& visited) {
        visited[node] = 1;
        tin[node] = low[node] = timer++;

        for (int adjNode : adj[node]) {
            if (!visited[adjNode]) {
                dfs(adjNode, adj, tin, low, ans, visited);
                low[node] = min(low[node], low[adjNode]);

                if (low[adjNode] > tin[node]) {
                    ans.push_back({node, adjNode});
                }
            } 
            
            else {
                low[node] = min(low[node], low[adjNode]);
            }
        }
    }

public:
    vector<vector<int>> findBridges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> tin(n, -1); // start time of DFS traversal on node i
        vector<int> low(n, -1); // lowest time of adjacent node that can be visited from node i apart from its parent
        vector<int> visited(n, 0);

        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, adj, tin, low, ans, visited);
            }
        }

        return ans;
    }
};
