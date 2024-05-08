#include <bits/stdc++.h?
using namespace std;

class Solution {
private:
    int timer = 0;

    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& visited, vector<int>& tin, vector<int>& low, vector<vector<int>>& ans) {
        visited[node] = 1;
        tin[node] = low[node] = timer++;

        for (int adjNode : adj[node]) {
            if (adjNode == parent) continue;

            if (visited[adjNode]) {
                // if the node has been visited, node -- adjNode obviously is not a bridge
                low[node] = min(low[node], low[adjNode]);
            } 
            
            else {
                dfs(adjNode, node, adj, visited, tin, low, ans);
                low[node] = min(low[node], low[adjNode]);

                // check for bridge node -- adjNode
                if (low[adjNode] > tin[node]) {
                    ans.push_back({node, adjNode});
                }
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
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, tin, low, ans);
            }
        }

        return ans;
    }
};