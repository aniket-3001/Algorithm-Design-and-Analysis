#include<bits/stdc++.h>
using namespace std;

void dfs1(int node, vector <vector <int>> &adj, vector <int> &visited, stack <int> &st) {
    visited[node] = 1;
    
    for (auto adjNode: adj[node]) {
        if (!visited[adjNode]) {
            dfs1(adjNode, adj, visited, st);
        }
    }
    
    st.push(node);
}

void dfs2(int node, vector <vector <int>> &adj, vector <int> &visited) {
    visited[node] = 1;
    
    for (auto adjNode: adj[node]) {
        if (!visited[adjNode]) {
            dfs2(adjNode, adj, visited);
        }
    }
}

int kosaraju(int V, vector<vector<int>>& adj)
{
    vector <int> visited(V, 0);
    stack <int> st;
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }
    
    vector <vector <int>> adjT(V); // reverse graph
    
    for (int i = 0; i < V; i++) {
        visited[i] = 0; // reset
        
        for (auto adjNode: adj[i]) {
            adjT[adjNode].push_back(i);
        }
    }
    
    int scc = 0;
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        
        if (!visited[node]) {
            scc++;
            dfs2(node, adjT, visited);
        }
    }
    
    return scc;
}