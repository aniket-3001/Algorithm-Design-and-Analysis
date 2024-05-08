#include <bits/stdc++.h>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<int>& visited, stack<int>& st) {
    visited[node] = 1;

    for (auto adjNode : adj[node]) {
        if (!visited[adjNode]) {
            dfs(adjNode, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& graph, int edges, int nodes) {
    vector <int> visited(nodes, 0);
    stack <int> st;
    vector <int> ans(nodes);

    vector<vector<int>> adj(nodes);

    for(vector<int> edge : graph) {
        adj[edge[0]].push_back(edge[1]);
    }

    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}